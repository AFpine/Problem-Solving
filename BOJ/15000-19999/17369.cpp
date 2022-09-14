#include <bits/stdc++.h>

// 17369 유령의 집

// update 220914

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
const int MAX = 300005;

int N, M, K, Q;
set<int> r[MAX], c[MAX];
map<pii, char> E;
map<pair<char, int>, pll> ans;
ll tmpans = 0, tmpsum = 0;

void solve(int dir, pii cur, ll dist) {
	if(dir == 0) {
		auto it = c[cur.second].find(cur.first);
		if(it == c[cur.second].begin()) return;
		it = prev(it);
		pii nxt = {(*it), cur.second};
		auto curE = E[nxt];
		dist += (cur.first - nxt.first);

		if(curE == '/') {
			solve(3, nxt, dist);
		}
		else if(curE == '\\') {
			solve(2, nxt, dist);
		}
		else {
			tmpans++;
			tmpsum += dist;
			solve(dir, nxt, dist);
		}
	}
	else if(dir == 1) {
		auto it = c[cur.second].upper_bound(cur.first);
		if(it == c[cur.second].end()) return;
		pii nxt = {(*it), cur.second};
		auto curE = E[nxt];
		dist += (nxt.first - cur.first);

		if(curE == '/') {
			solve(2, nxt, dist);
		}
		else if(curE == '\\') {
			solve(3, nxt, dist);
		}
		else {
			tmpans++;
			tmpsum += dist;
			solve(dir, nxt, dist);
		}
	}
	else if(dir == 2) {
		auto it = r[cur.first].find(cur.second);
		if(it == r[cur.first].begin()) return;
		it = prev(it);
		pii nxt = {cur.first, (*it)};
		auto curE = E[nxt];
		dist += (cur.second - nxt.second);

		if(curE == '/') {
			solve(1, nxt, dist);
		}
		else if(curE == '\\') {
			solve(0, nxt, dist);
		}
		else {
			tmpans++;
			tmpsum += dist;
			solve(dir, nxt, dist);
		}
	}
	else {
		auto it = r[cur.first].upper_bound(cur.second);
		if(it == r[cur.first].end()) return;
		pii nxt = {cur.first, (*it)};
		auto curE = E[nxt];
		dist += (nxt.second - cur.second);

		if(curE == '/') {
			solve(0, nxt, dist);
		}
		else if(curE == '\\') {
			solve(1, nxt, dist);
		}
		else {
			tmpans++;
			tmpsum += dist;
			solve(dir, nxt, dist);
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>K>>Q;

	for(int i = 1; i <= K; ++i) {
		int x, y;
		char ch;
		cin>>x>>y>>ch;
		E[pii(x, y)] = ch;
		r[x].insert(y);
		c[y].insert(x);
	}

	while(Q--) {
		char qc;
		int qn;
		tmpans = tmpsum = 0;

		cin>>qc>>qn;

		if(ans.find(pair<char, int>(qc, qn)) != ans.end()) {cout<<ans[pair<char, int>(qc, qn)].first<<" "<<ans[pair<char, int>(qc, qn)].second<<'\n'; continue;};

		int dir;
		pii st;
		if(qc == 'U') { dir = 1; st = {0, qn}; }
		else if(qc == 'D') { dir = 0; st = {N+1, qn}; }
		else if(qc == 'L') { dir = 3; st = {qn, 0}; }
		else { dir = 2; st = {qn, M+1}; }

		solve(dir, st, 0);
		ans[pair<char, int>(qc, qn)] = {tmpans, tmpsum};
		cout<<tmpans<<" "<<tmpsum<<'\n';
	}

	return 0;
}