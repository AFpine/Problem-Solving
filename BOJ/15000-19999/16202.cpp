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
const int MAX = 1010;

struct E {
    int u, v, w;
};

int N, M, K;
vector<E> edge;
int uf[MAX];
bool selected[10101];

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

int solve(int t) {
    int ret = INF;
    int total = 0;
    fill(uf, uf+MAX, -1);
    
    for(auto &e : edge) {
        if(selected[e.w]) continue;
        if(find(e.v) == find(e.u)) continue;
        merge(e.u, e.v);
        total += e.w;
        ret = min(ret, e.w);
    }

    bool invalid = false;
    int r = find(1);
    for(int i = 2; i <= N; ++i) if(find(i) != r) invalid = true;
    if(invalid) {
        return 0;
    }
    selected[ret] = true;
    return total;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>M>>K;
    for(int i = 1; i <= M; ++i) {
        int a, b;
        cin>>a>>b;
        edge.push_back({a, b, i});
    }

    sort(edge.begin(), edge.end(), [](E a, E b) {
        return a.w < b.w;
    });
    for(int i = 1; i <= K; ++i) {
        cout<<solve(i)<<" ";
    }

	return 0;
}