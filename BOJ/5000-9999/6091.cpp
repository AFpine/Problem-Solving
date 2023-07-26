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
const int MAX = 1111;

struct Edge {
	int u, v, w;
};

int N;
vector<Edge> edge;
int uf[MAX];
vector<int> result[MAX];

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf, uf+MAX, -1);

	cin>>N;
	for(int i = 1; i < N; ++i) {
		for(int j = i + 1; j <= N; ++j) {
			int t;
			cin>>t;
			edge.push_back({i, j, t});
		}
	}

	sort(edge.begin(), edge.end(), [](Edge a, Edge b) {
		return a.w < b.w;
	});

	for(auto &e : edge) {
		if(find(e.u) == find(e.v)) continue;
		merge(e.u, e.v);
		result[e.u].push_back(e.v);
		result[e.v].push_back(e.u);
	}

	for(int i = 1; i <= N; ++i) sort(result[i].begin(), result[i].end());
	for(int i = 1; i <= N; ++i) {
		cout<<sz(result[i])<<" ";
		for(auto &e : result[i]) cout<<e<<" ";
		cout<<'\n';
	}

	return 0;
}