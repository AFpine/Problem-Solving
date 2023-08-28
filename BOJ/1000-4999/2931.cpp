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
const int MAX = 30;

int R, C;
char board[MAX][MAX];
bool visited[MAX][MAX];
pii st, en;
pii resp;
char resc;



int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int nxt(pii p, int dir) {
    int x = p.first + dx[dir];
    int y = p.second + dy[dir];
    if(x < 1 || x > R || y < 1 || y > C || board[x][y] == '.') return -1;
    if(board[x][y] == 'Z') return dir;
    
    auto c = board[x][y];
    if(dir == 1) {
        if(c == '|' || c == '+') return 1;
        else if(c == '2') return 3;
        else if(c == '3') return 4;
        else return -1;
    }
    else if(dir == 2) {
        if(c == '|' || c == '+') return 2;
        else if(c == '1') return 3;
        else if(c == '4') return 4;
        else return -1;
    }
    else if(dir == 3) {
        if(c == '-' || c == '+') return 3;
        else if(c == '3') return 2;
        else if(c == '4') return 1;
        else return -1;
    }
    else {
        if(c == '-' || c == '+') return 4;
        else if(c == '1') return 1;
        else if(c == '2') return 2;
        else return -1;
    }
}

bool bfs() {
    queue<pii> Q;
    queue<int> dirQ;
    bool invalid = false;
    memset(visited, false, sizeof(visited));

    visited[st.first][st.second] = true;
    for(int dir = 1; dir <= 4; ++dir) {
        int x = st.first + dx[dir];
        int y = st.second + dy[dir];

        if(x < 1 || x > R || y < 1 || y > C || board[x][y] == '.') continue;
        auto c = board[x][y];
        if(dir == 1) {
            if(c == '|' || c == '+' || c == '2' || c == '3') {
                Q.push(st);
                dirQ.push(dir);
            }
        }
        else if(dir == 2) {
            if(c == '|' || c == '+' || c == '1' || c == '4') {
                Q.push(st);
                dirQ.push(dir);
            } 
        }
        else if(dir == 3) {
            if(c == '-' || c == '+' || c == '3' || c == '4') {
                Q.push(st);
                dirQ.push(dir);
            } 
        }
        else {
            if(c == '-' || c == '+' || c == '1' || c == '2') {
                Q.push(st);
                dirQ.push(dir);
            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        auto curd = dirQ.front();
        dirQ.pop();

        if(cur == en) break;

        auto n = nxt(cur, curd);
        if(n == -1) continue;
        
        visited[cur.first + dx[curd]][cur.second + dy[curd]] = true;
        Q.push({cur.first + dx[curd], cur.second + dy[curd]});
        dirQ.push(n);
    }

    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            if(board[i][j] == '.') continue;
            if(visited[i][j] == false) invalid = true;
        }
    }

    if(invalid) return false;
    else return true;
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
            cin>>board[i][j];
            if(board[i][j] == 'M') st = {i, j};
            else if(board[i][j] == 'Z') en = {i, j};
        }
    }
    
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            if(board[i][j] != '.') continue;
            pii p = {i, j};
            for(int k = 1; k <= 7; ++k) {
                if(k == 1) board[p.first][p.second] = '|';
                else if(k == 2) board[p.first][p.second] = '-';
                else if(k == 3) board[p.first][p.second] = '+';
                else if(k == 4) board[p.first][p.second] = '1';
                else if(k == 5) board[p.first][p.second] = '2';
                else if(k == 6) board[p.first][p.second] = '3';
                else board[p.first][p.second] = '4';

                bool invalid = false;
                for(int dir = 1; dir <= 4; ++dir) {
                    int x = p.first + dx[dir];
                    int y = p.second + dy[dir];

                    if(x < 1 || x > R || y < 1 || y > C) continue;
                    if(board[x][y] == 'M' || board[x][y] == 'Z') {
                        if(dir == 1) {
                            if(k == 1 || k == 3 || k == 4 || k == 7) invalid = true;
                        }
                        else if(dir == 2) {
                            if(k == 1 || k == 3 || k == 5 || k == 6) invalid = true;
                        }
                        else if(dir == 3) {
                            if(k == 2 || k == 3 || k == 4 || k == 5) invalid = true;
                        }
                        else {
                            if(k == 2 || k == 3 || k == 6 || k == 7) invalid = true;
                        }
                    }
                }

                for(int dir = 1; dir <= 4; ++dir) {
                    int x = p.first + dx[dir];
                    int y = p.second + dy[dir];

                    if(k == 1) {
                        if((dir == 1 || dir == 2) && (x < 1 || x > R || y < 1 || y > C || board[x][y] == '.')) invalid = true;
                    }
                    else if(k == 2) {
                        if((dir == 3 || dir == 4) && (x < 1 || x > R || y < 1 || y > C || board[x][y] == '.')) invalid = true;
                    }
                    else if(k == 3) {
                        if(x < 1 || x > R || y < 1 || y > C || board[x][y] == '.') invalid = true;
                    }
                    else if(k == 4) {
                        if((dir == 1 || dir == 3) && (x < 1 || x > R || y < 1 || y > C || board[x][y] == '.')) invalid = true;
                    }
                    else if(k == 5) {
                        if((dir == 2 || dir == 3) && (x < 1 || x > R || y < 1 || y > C || board[x][y] == '.')) invalid = true;
                    }
                    else if(k == 6) {
                        if((dir == 2 || dir == 4) && (x < 1 || x > R || y < 1 || y > C || board[x][y] == '.')) invalid = true;
                    }
                    else {
                        if((dir == 1 || dir == 4) && (x < 1 || x > R || y < 1 || y > C || board[x][y] == '.')) invalid = true;
                    }
                }

                if(invalid) {
                    board[p.first][p.second] = '.';
                    continue;
                }

                if(bfs()) {
                    resp = p;
                    resc = board[p.first][p.second];
                }
                board[p.first][p.second] = '.';
            }
        }
    }

    cout<<resp.first<<" "<<resp.second<<" "<<resc<<'\n';
    
	return 0;
}
