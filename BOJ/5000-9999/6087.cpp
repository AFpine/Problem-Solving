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
const int MAX = 111;

struct wv {
    int w;
    pii v;
    int dir;
    bool operator<(const wv& rhs) const {
        return w > rhs.w;
    }
};

char board[MAX][MAX];
int W, H;
pii st, en;
int dist[MAX][MAX][5];
vector<wv> adj[MAX][MAX][5];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    for(int i = 0; i < MAX; ++i) for(int j = 0; j < MAX; ++j) for(int k = 0; k < 4; ++k) dist[i][j][k] = INF;
    priority_queue<wv> pq;

    for(int i = 0; i < 4; ++i) {
        dist[st.first][st.second][i] = 0;
        pq.push({0, st, i});
    }
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(dist[cur.v.first][cur.v.second][cur.dir] < cur.w) continue;
        
        for(auto &e : adj[cur.v.first][cur.v.second][cur.dir]) {
            if(dist[e.v.first][e.v.second][e.dir] > cur.w + e.w) {
                dist[e.v.first][e.v.second][e.dir] = cur.w + e.w;
                pq.push({dist[e.v.first][e.v.second][e.dir], e.v, e.dir});
            }
        }
    }
    int result = INF;
    for(int i = 0; i < 4; ++i) {
        result = min(result, dist[en.first][en.second][i]);
    }
    cout<<result;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>W>>H;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            cin>>board[i][j];
            if(board[i][j] == 'C') {
                if(st == pii(0, 0)) st = {i, j};
                else en = {i, j};
            }
        }
    }

    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            for(int dir = 0; dir < 4; ++dir) {
                for(int ndir = 0; ndir < 4; ++ndir) {
                    if(abs(dir-ndir) == 2) continue;
                    int x = i + dx[ndir];
                    int y = j + dy[ndir];

                    if(x < 1 || x > H || y < 1 || y > W || board[x][y] == '*') continue;
                    
                    if(dir == ndir) adj[i][j][dir].push_back({0, {x, y}, ndir});
                    else adj[i][j][dir].push_back({1, {x, y}, ndir});
                }
            }
        }
    }

    solve();

	return 0;
}