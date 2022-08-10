#include <bits/stdc++.h>

// 6195 Fence Repair

// update 220810

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAX = 20005;

int N;
ll result;

priority_queue<int, vector<int>, greater<int>> pq;

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		int t;
		cin>>t;
		pq.push(t);
	}
}

void solve() {
	while(sz(pq) >= 2) {
		auto t1 = pq.top();
		pq.pop();
		auto t2 = pq.top();
		pq.pop();

		result += (t1+t2);
		pq.push(t1+t2);
	}
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}