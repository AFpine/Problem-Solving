#include <bits/stdc++.h>
 
// 1045 도로

// update 220804

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int MAXN = 55;
const int MAXM = 1005;

int N, M;
int check[MAXN];
bool selected[MAXM];
int uf[MAXN];
vector<pii> edge;

int find(int a) {
	if(uf[a] < 0) return a;
	else return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

void input() {
	cin>>N>>M;
	char c;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cin>>c;
			if(c == 'Y') {
				if(i < j) edge.push_back({i, j});
			}
		}
	}
	sort(edge.begin(), edge.end());
	fill(uf, uf+MAXN, -1);
}

void solve() {
	if(N == 1 && M == 0) {
		cout<<"0";
		return;
	}
	bool mst = false;
	int cnt = 0;
	for(int i = 0; i < sz(edge); ++i) {
		auto e = edge[i];
		if(find(e.first) != find(e.second)) {
			cnt++;
			selected[i] = true;
			check[e.first]++;
			check[e.second]++;
			merge(e.first, e.second);
			if(-uf[find(e.first)] == N) {
				mst = true;
				break;
			}
		}
	}
	if(!mst || cnt > M) {
		cout<<"-1";
		return;
	}
	else if(cnt < M)
	{
		for(int i = 0; i < sz(edge); ++i) {
			if(selected[i]) continue;
			auto e = edge[i];
			check[e.first]++;
			check[e.second]++;
			if(++cnt == M) break;
		}
	}

	if(cnt == M) {
		for(int i = 0; i < N; ++i) {
			cout<<check[i]<<" ";
		}
	}
	else {
		cout<<"-1";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}