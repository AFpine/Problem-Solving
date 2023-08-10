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
const int MAX = 30;

struct wv {
    int w;
    int v;
    bool operator<(const wv& rhs) const {
        return w > rhs.w;
    }
};

int N, M;
int dist[MAX], prv[MAX];
vector<wv> adj[MAX];

void dijkstra() {
    priority_queue<wv> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.v] < cur.w) continue;
        for(auto &e : adj[cur.v]) {
            if(dist[e.v] > cur.w + e.w) {
                dist[e.v] = cur.w + e.w;
                prv[e.v] = cur.v;
                pq.push({dist[e.v], e.v});
            }
        }
    }
}

void init() {
    fill(dist, dist+MAX, INF);
    fill(prv, prv+MAX, -1);
    for(int i = 0; i < MAX; ++i) adj[i].clear();
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin>>T;
    for(int tt = 1; tt <= T; ++tt) {
        init();

        cin>>N>>M;
        for(int i = 1; i <= N; ++i) {
            int a, b, c;
            cin>>a>>b>>c;
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        dijkstra();
        cout<<"Case #"<<tt<<": ";
        if(dist[M-1] == INF) cout<<-1<<'\n';
        else {
            vector<int> result;
            int cur = M-1;
            while(cur != -1) {
                result.push_back(cur);
                cur = prv[cur];
            }
            reverse(result.begin(), result.end());
            for(auto &i : result) cout<<i<<" ";
            cout<<'\n';
        }
    }

	return 0;
}