// #define LOCAL_TEST

#include <bits/stdc++.h>

// 15922 아우으 우아으이야!!

// update 220902

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
const long long MOD = 1000000007;
const int MAX = 100005;

int N;
ll st, en;
pll line[MAX];
ll result = 0;

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>line[i].first>>line[i].second;
	}
}

void solve() {
	st = line[1].first, en = line[1].second;
	for(int i = 2; i <= N; ++i) {
		if(line[i].first > en) {
			result += en - st;
			st = line[i].first;
			en = line[i].second;
		}
		else if(line[i].second <= en) continue;
		else {
			en = line[i].second;
		}
	}
	result += en - st;

	cout<<result;
}

int main() {

	#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}