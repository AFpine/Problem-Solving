#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1294

// 221111

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 30;

int N;
string S;

struct cmp {
	bool operator() (const string &a , const string &b) {
		return a+b > b+a;
	}
};

priority_queue<string, vector<string>, cmp> pq;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) { cin>>S; pq.push(S); }

	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		cout<<cur[0];
		if(sz(cur) > 1) pq.push(cur.substr(1, sz(cur)-1));
	}

	return 0;
}