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
const int MAX = 25;

int w, h, cnt;
pii start;
char board[MAX][MAX];
int visited[MAX][MAX], dist[MAX][MAX];
vector<pii> dirty;
ll dp[15][1<<15];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int st) {
    memset(visited, -1, sizeof(visited));
    visited[dirty[st].first][dirty[st].second] = 0;
    queue<pii> Q;
    Q.push(dirty[st]);

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir) {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            if(x < 1 || x > h || y < 1 || y > w) continue;
            if(visited[x][y] > 0 || board[x][y] == 'x') continue;
            visited[x][y] = visited[cur.first][cur.second] + 1;
            Q.push({x, y});
        }
    }
    for(int i = 0; i <= cnt; ++i) {
        if(visited[dirty[i].first][dirty[i].second] == -1) dist[st][i] = dist[i][st] = INF;
        else dist[st][i] = dist[i][st] = visited[dirty[i].first][dirty[i].second];
    }
}

ll f(int cur, int bit) {
    if(bit == (1<<(cnt+1))-1) return 0;

    auto &ret = dp[cur][bit];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < cnt; ++i) {
        if(bit & (1<<i)) continue;
        ret = min(ret, f(i, bit|(1<<i)) + dist[cur][i]);
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    while(true) {
        cin>>w>>h;
        if(w == 0 && h == 0) break;

        memset(dist, INF, sizeof(dist));
        memset(dp, -1, sizeof(dp));
        dirty.clear();

        for(int i = 1; i <= h; ++i) {
            for(int j = 1; j <= w; ++j) {
                cin>>board[i][j];
                if(board[i][j] == '*') dirty.push_back({i, j});
                else if(board[i][j] == 'o') start = {i, j};
            }
        }

        cnt = sz(dirty);
        dirty.push_back(start);
        for(int i = 0; i <= cnt; ++i) bfs(i);

        auto result = f(cnt, 1<<cnt);
        if(result >= INF) cout<<"-1\n";
        else cout<<result<<'\n';
    }

	return 0;
}