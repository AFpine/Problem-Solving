#include <bits/stdc++.h>

// 1666

// 221028

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 101010;

struct REC {
	int x1, x2, y1, y2;
};

struct PQREC {
	int x, y, l;
	bool operator< (const PQREC &rhs) const {
		return rhs.x < x;
	}
};

int N;
vector<int> lis;
REC rec[MAX];
// min heap
priority_queue<PQREC> pq;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>rec[i].x1>>rec[i].y1>>rec[i].x2>>rec[i].y2;
	}
	sort(rec+1, rec+1+N, [](REC a, REC b) {
		if(a.x1 == b.x1) return a.y1 < b.y1;
		return a.x1 < b.x1;
	});

	// 직사각형들은 전부 정렬되어있다 (시작점에 대해)
	for(int i = 1; i <= N; ++i) {
		while(!pq.empty() && pq.top().x < rec[i].x1) {
			auto cur = pq.top();
			pq.pop();

			if(cur.l >= sz(lis)) lis.push_back(cur.y);
			// lis의 마지막 직사각형의 y값이 작을수록 lis가 더 길어질 가능성이 있다
			lis[cur.l] = min(lis[cur.l], cur.y);
		}

		auto lb = lower_bound(lis.begin(), lis.end(), rec[i].y1) - lis.begin();
		pq.push({rec[i].x2, rec[i].y2, lb});
	}

	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if(cur.l >= sz(lis)) lis.push_back(cur.y);
	}
	cout<<sz(lis);

	return 0;
}