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
const long long MOD = 1000000LL;
const int MAX = 1111111;

int R, C;
char board[1010][1010];
int compsize;
int compidx[MAX];
map<int, int> mp;
vector<pii> comp[MAX];
vector<pii> v;
int dist[MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int T;

int idx(int i, int j) {
    return i*1010 + j;
}

void dfs(int i, int j) {
    for(int dir = 0; dir < 4; ++dir) {
        int x = i + dx[dir];
        int y = j + dy[dir];
        if(x < 1 || x > R || y < 1 || y > C || board[x][y] == '#') continue;
        if(dist[idx(x, y)] >= 0) continue;

        dist[idx(x, y)] = dist[idx(i, j)] + 1;
        dfs(x, y);
    }
}

void merge(int i, int j, int cnt) {
    comp[cnt].push_back({i, j});

    for(int dir = 0; dir < 4; ++dir) {
        int x = i + dx[dir];
        int y = j + dy[dir];
        if(x < 1 || x > R || y < 1 || y > C || board[x][y] == '#') continue;
        if(dist[idx(x, y)] >= 0) continue;

        dist[idx(x, y)] = dist[idx(i, j)] + 1;
        compidx[idx(x, y)] = cnt;
        merge(x, y, cnt);
    }
}

void init() {
    for(int i = 0; i < MAX; ++i) {
        comp[i].clear();
        dist[i] = -1;
        compidx[i] = 0;
    }
    mp.clear();
    v.clear();
    compsize = 0;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>T;
    while(T--) {
        init();
        cin>>C>>R;

        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                cin>>board[i][j];
                if(board[i][j] == '.') v.push_back({i, j});
            }
        }
        
        for(auto &p : v) {
            if(dist[idx(p.first, p.second)] > 0) continue;
            dist[idx(p.first, p.second)] = 0;
            compsize++;
            compidx[idx(p.first, p.second)] = compsize;
            merge(p.first, p.second, compsize);
        }

        for(int i = 1; i <= compsize; ++i) {
            int mx = -1;
            pii j = {-1, -1};
            for(auto &e : comp[i]) {
                if(dist[idx(e.first, e.second)] > mx) {
                    mx = dist[idx(e.first, e.second)];
                    j = e;
                }
                dist[idx(e.first, e.second)] = -1;
            }
            dist[idx(j.first, j.second)] = 0;
            dfs(j.first, j.second);
        }

        int result = -1;
        for(auto &i : v) {
            result = max(result, dist[idx(i.first, i.second)]);
        }

        cout<<"Maximum rope length is "<<result<<".\n";
    }

	return 0;
}