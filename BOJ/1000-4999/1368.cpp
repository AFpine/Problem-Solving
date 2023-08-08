#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 333;

struct Edge {
    ll w;
    int u, v;
};

int N;
int uf[MAX];
vector<Edge> edge;
ll result;

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

void mst() {
    fill(uf, uf+MAX, -1);
    sort(edge.begin(), edge.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    for(auto &e : edge) {
        if(find(e.u) == find(e.v)) continue;
        merge(e.u, e.v);
        result += e.w;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    for(int i = 1; i <= N; ++i) {
        ll w;
        cin>>w;
        edge.push_back({w, 0, i});
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            ll w;
            cin>>w;
            edge.push_back({w, i, j});
        }
    }

    mst();
    cout<<result;

	return 0;
}