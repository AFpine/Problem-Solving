#include <bits/stdc++.h>

// 17193 I Would Walk 500 Miles

// update 220711

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 7600;
const long long MOD = 2019201997;

int N, K;
ll dist[MAX];
bool visited[MAX];
// vector<ll> result;

ll calculate(int x, int y) {
	return ((1LL*x*2019201913) + (1LL*y*2019201949)) % MOD;
}

void MST() {
	fill(dist, dist+MAX, MOD);
	fill(visited, visited+MAX, false);

	for(int it = 0; it < N; ++it) {
		int minV = -1;
		for(int i = 1; i <= N; ++i) {
			if(!visited[i] && (minV == -1 || dist[minV] > dist[i])) minV = i;
		}
		visited[minV] = true;
		for(int i = 1; i <= N; ++i) {
			if(visited[i]) continue;
			dist[i] = min(dist[i] , calculate(min(i,minV), max(i,minV)));
		}
	}
}

void solve() {
	MST();

	sort(dist+1, dist+1+N);

	cout<<dist[N+1-K];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;

	solve();
	

	return 0;
}