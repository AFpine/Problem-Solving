// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const int MAX = 50505;

int N, M;
int cnt;
int uf[MAX];
int visited[MAX];
vector<pii> edge;
vector<int> adj[MAX];
bool invalid = false;

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

void dfs(int v, int prv) {
    for(auto &e : adj[v]) {
        if(e == prv) {
            invalid = true;
            return;
        }
        else if(visited[e] > 0) continue;
        visited[e] = visited[v];
        dfs(e, prv);
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

    fill(uf, uf+MAX, -1);

    cin>>N>>M;
    
    for(int i = 1; i <= M; ++i) {
        int a, b;
        char c;
        cin>>a>>c>>b;
        if(c == '=') {
            merge(a, b);
        }
        else edge.push_back({a, b});
    }

    for(auto &e : edge) {
        if(find(e.first) == find(e.second)) {
            cout<<"inconsistent";
            return 0;
        }
        adj[find(e.first)].push_back(find(e.second));
    }
    
    for(int i = 0; i < N; ++i) {
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    for(int i = 0; i < N; ++i) {
        if(visited[find(i)] > 0) continue;
        visited[find(i)]++;
        dfs(find(i), find(i));
    }

    if(invalid) cout<<"inconsistent";
    else cout<<"consistent";

	return 0;
}