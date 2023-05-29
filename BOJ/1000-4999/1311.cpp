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
const int MAX = 444;

int N, h, st, en;
int c[MAX][MAX], f[MAX][MAX];
int d[MAX][MAX], prv[MAX];
vector<int> adj[MAX];
int mc, mf;

void input() {
	cin>>N;
	h = N+1;
	st = 0;
	en = 2*N+2;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			c[i][j+h] = 1;
			cin>>d[i][j+h];
			d[j+h][i] = -d[i][j+h];
			adj[i].push_back(j+h);
			adj[j+h].push_back(i);
		}
		adj[st].push_back(i);
		adj[i].push_back(st);
		c[st][i] = 1;
		d[st][i] = d[i][st] = 0;
		adj[i+h].push_back(en);
		adj[en].push_back(i+h);
		c[i+h][en] = 1;
		d[i+h][en] = d[en][i+h] = 0;
	}
}

void spfa() {
	memset(prv, -1, sizeof(prv));
	vector<int> dist(MAX, INF);
	vector<bool> inQ(MAX);
	queue<int> q;
	q.push(st);
	dist[st] = 0;
	inQ[st] = true;
	while(!q.empty()) {
		int now = q.front();
		q.pop();

		inQ[now] = false;
		for(int next : adj[now]) {
			if(dist[now] + d[now][next] < dist[next] && c[now][next] - f[now][next] > 0) {
				dist[next] = dist[now] + d[now][next];
				prv[next] = now;
				if(!inQ[next]) {
					inQ[next] = true;
					q.push(next);
				}
			}
		}
	}
}
void flow() {
	int block = INF;
	for(int i = en; i != st; i = prv[i]) {
		block = min(block, c[prv[i]][i] - f[prv[i]][i]);
	}
	for(int i = en; i != st; i = prv[i]) {
		mc += d[prv[i]][i] * block;
		f[prv[i]][i] += block;
		f[i][prv[i]] -= block;
	}
	mf += block;
}
void mcmf() {
	while(true) {
		spfa();
		if(prv[en] == -1) break;
		flow();
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

	input();
	mcmf();
	cout<<mc;

	return 0;
}