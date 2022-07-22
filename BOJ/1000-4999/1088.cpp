#include <bits/stdc++.h>
 
// 1088 케이크
 
// update 220722

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 100005;

struct Cake {
	int idx, cnt;
	double val;
};

struct compare {
	bool operator()(const Cake &a, const Cake &b) {
		return a.val < b.val;
	}
};

int N, M;
double minv, maxv;
double cake[55];
priority_queue<Cake, vector<Cake>, compare> pq;

void input() {
	cin>>N;
	minv = INF, maxv = -1;
	for(int i = 1; i <= N; ++i) {
		cin>>cake[i];
		minv = min(minv, cake[i]);
		maxv = max(maxv, cake[i]);

		pq.push({i, 1, cake[i]});
	}
	cin>>M;
}

void solve() {
	double result = maxv - minv;
	while(M--) {
		auto c = pq.top();
		pq.pop();

		auto temp = c;
		temp.idx = c.idx;
		temp.cnt = c.cnt + 1;
		temp.val = cake[c.idx] / temp.cnt;

		pq.push(temp);
		minv = min(minv, temp.val);
		result = min(result, pq.top().val - minv);
	}
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout<<fixed;
	cout.precision(16);

	input();
	solve();
 
	return 0;
}