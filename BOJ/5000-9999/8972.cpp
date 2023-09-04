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
const int MAX = 111;

int R, C;
int board[MAX][MAX];
string S;
int result;
pii player;
vector<pii> robots;

char resboard[MAX][MAX];

int dx[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

int dist(pii a) {
    return abs(player.first - a.first) + abs(player.second - a.second);
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>R>>C;
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            char c;
            cin>>c;
            if(c == 'I') player = {i, j};
            else if(c == 'R') {
                robots.push_back({i, j});
                board[i][j]++;
            }
        }
    }
    cin>>S;

    bool invalid = false;
    for(int s = 0; s < S.length(); ++s) {
        player = {player.first + dx[S[s] - '0'], player.second + dy[S[s] - '0']};
        if(board[player.first][player.second] > 0) { 
            invalid = true; 
            break; 
        }
        
        memset(board, 0, sizeof(board));

        for(auto &r : robots) {
            int mn = INF;
            int mov = 0;
            for(int dir = 1; dir <= 9; ++dir) {
                int x = r.first + dx[dir];
                int y = r.second + dy[dir];
                if(x < 1 || x > R || y < 1 || y > C) continue;
                if(dist({x, y}) < mn) {
                    mn = dist({x, y});
                    mov = dir;
                }
            }
            if(player == pii({r.first + dx[mov], r.second + dy[mov]})) invalid = true;
            board[r.first + dx[mov]][r.second + dy[mov]]++;
        }

        if(invalid) break;

        robots.clear();
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                if(board[i][j] == 1) robots.push_back({i, j});
            }
        }

        result++;
    }

    if(invalid) {
        cout<<"kraj "<<result+1<<'\n';
    }
    else {
        memset(resboard, '.', sizeof(resboard));
        resboard[player.first][player.second] = 'I';
        for(auto &r : robots) resboard[r.first][r.second] = 'R';

        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) cout<<resboard[i][j];
            cout<<'\n';
        }
    }

	return 0;
}
