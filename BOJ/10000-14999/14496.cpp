#include <bits/stdc++.h>

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
const int MAX = 1010;

int N, M, st, en, cnt, dist[MAX];
vector<int> adj[MAX];
map<string, int> mp;

void bfs(int st) {
	queue<int> Q;
	
	dist[st] = 0;
	Q.push(st);
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(auto &e : adj[cur]) {
			if(dist[e] > -1) continue;
			dist[e] = dist[cur] + 1;
			Q.push(e);
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

	memset(dist, -1, sizeof(dist));
	string s1, s2;
	
	cin>>s1;
	mp[s1] = st = ++cnt;
	
	cin>>s2;
	if(mp[s2] > 0) en = mp[s2];
	else mp[s2] = en = ++cnt;

	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		cin>>s1>>s2;
		if(mp[s1] == 0) mp[s1] = ++cnt;
		if(mp[s2] == 0) mp[s2] = ++cnt;
		adj[mp[s1]].push_back(mp[s2]);
		adj[mp[s2]].push_back(mp[s1]);
	}

	bfs(st);

	cout<<dist[en];

	return 0;
}