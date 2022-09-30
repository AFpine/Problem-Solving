#include <bits/stdc++.h>

// 17469 트리의 색깔과 쿼리

// update 220930

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
const int MAX = 100005;

int N, Q, uf[MAX], par[MAX];
set<int> s[MAX];
vector<pii> query;

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(sz(s[b]) > sz(s[a])) swap(a, b);
	for(auto &e : s[b]) s[a].insert(e);
	uf[a] += uf[b];
	uf[b] = a;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf, uf+MAX, -1);

	cin>>N>>Q;
	for(int i = 2; i <= N; ++i) {
		cin>>par[i];
	}
	for(int i = 1; i <= N; ++i) {
		int c;
		cin>>c;
		s[i].insert(c);
	}

	for(int t = 0; t < N + Q - 1; ++t) {
		int op, a;
		cin>>op>>a;
		query.push_back({op, a});
	}
	
	stack<int> ans;
	reverse(all(query));
	for(auto &p : query) {
		if(p.first == 1) {
			merge(p.second, par[p.second]);
		}
		else {
			ans.push(sz(s[find(p.second)]));
		}
	}
	while(!ans.empty()) { cout<<ans.top()<<"\n"; ans.pop(); }
	
	return 0;
}