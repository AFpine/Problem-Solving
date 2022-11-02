#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2453

// 221102

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
const int MAXV = 255;
const int D = 105;

int N, st = 0, en = MAXV-1;
int c[MAXV][MAXV], f[MAXV][MAXV];
int d[MAXV][MAXV], prv[MAXV];
vector<int> adj[MAXV];
int mFlow, mCost;

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		adj[st].push_back(i);
		adj[i].push_back(st);
		adj[D+i].push_back(en);
		adj[en].push_back(D+i);
		c[st][i] = 1;
		c[D+i][en] = 1;
		for(int j = 1; j <= N; ++j) {
			cin>>d[i][D+j];
			c[i][D+j] = 1;
			d[D+j][i] = -d[i][D+j];
			adj[i].push_back(D+j);
			adj[D+j].push_back(i);
		}
	}
}

void spfa() {
	memset(prv, -1, sizeof(prv));
	vector<int> dist(MAXV, INF);
	vector<bool> inQ(MAXV);

	queue<int> q;
	q.push(st);
	dist[st] = 0, inQ[st] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		inQ[now] = false;

		for (int next : adj[now]) {
			if (dist[now] + d[now][next] < dist[next] && c[now][next] - f[now][next] > 0) {
				dist[next] = dist[now] + d[now][next];
				prv[next] = now;
				if (!inQ[next]) {
					inQ[next] = true;
					q.push(next);
				}
			}
		}
	}
}

void flow() {
	int block = INF;
	for (int i = en; i != st; i = prv[i]) {
		block = min(block, c[prv[i]][i] - f[prv[i]][i]);
	}
	for (int i = en; i != st; i = prv[i]) {
		mCost += d[prv[i]][i] * block;
		f[prv[i]][i] += block;
		f[i][prv[i]] -= block;
	}
	mFlow += block;
}

void mcmf() {
	while (1) {
		spfa();
		if (prv[en] == -1) break;
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

	cout<<mCost;

	return 0;
}
