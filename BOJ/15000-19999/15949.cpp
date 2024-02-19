#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M;
char board[111][111];
int idx;
vector<pii> programs[10101];
int program_idx[111][111];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

pii st;
int PD = 3, CC = 0;

void dfs(pii v, int i) {
    for(int dir = 0; dir < 4; ++dir) {
        int x = v.first + dx[dir];
        int y = v.second + dy[dir];
        if(x < 1 || x > N || y < 1 || y > M) continue;
        if(board[x][y] != board[v.first][v.second]) continue;
        if(program_idx[x][y] > 0) continue;
        
        program_idx[x][y] = i;
        programs[i].push_back({x, y});
        dfs({x, y}, i);
    }
}

void showing() {
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cout<<program_idx[i][j];
        }
        cout<<"\n";
    }
}

void indexing() {
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if(board[i][j] == 'X') continue;
            if(program_idx[i][j] > 0) continue;
            program_idx[i][j] = ++idx;
            programs[idx].push_back({i, j});
            dfs({i, j}, idx);
        }
    }
}

pii last_codel(int pidx, int pd, int cc) {
    if(pd == 0 && cc == 0) {
        pii ret = {-1, -1};
        for(auto &p : programs[pidx]) {
            if(p.first > ret.first) {
                ret = p;
            }
            else if(p.first == ret.first && p.second > ret.second) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 0 && cc == 1) {
        pii ret = {-1, 111};
        for(auto &p : programs[pidx]) {
            if(p.first > ret.first) {
                ret = p;
            }
            else if(p.first == ret.first && p.second < ret.second) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 1 && cc == 0) {
        pii ret = {-1, 111};
        for(auto &p : programs[pidx]) {
            if(p.second < ret.second) {
                ret = p;
            }
            else if(p.second == ret.second && p.first > ret.first) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 1 && cc == 1) {
        pii ret = {111, 111};
        for(auto &p : programs[pidx]) {
            if(p.second < ret.second) {
                ret = p;
            }
            else if(p.second == ret.second && p.first < ret.first) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 2 && cc == 0) {
        pii ret = {111, 111};
        for(auto &p : programs[pidx]) {
            if(p.first < ret.first) {
                ret = p;
            }
            else if(p.first == ret.first && p.second < ret.second) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 2 && cc == 1) {
        pii ret = {111, -1};
        for(auto &p : programs[pidx]) {
            if(p.first < ret.first) {
                ret = p;
            }
            else if(p.first == ret.first && p.second > ret.second) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 3 && cc == 0) {
        pii ret = {111, -1};
        for(auto &p : programs[pidx]) {
            if(p.second > ret.second) {
                ret = p;
            }
            else if(p.second == ret.second && p.first < ret.first) {
                ret = p;
            }
        }
        return ret;
    }
    else if(pd == 3 && cc == 1) {
        pii ret = {-1, -1};
        for(auto &p : programs[pidx]) {
            if(p.second > ret.second) {
                ret = p;
            }
            else if(p.second == ret.second && p.first > ret.first) {
                ret = p;
            }
        }
        return ret;
    }
    return {-1, -1};
}


pii execute(pii p) {
    // cout<<"\n"<<PD<<" "<<CC<<" ";
    cout<<board[p.first][p.second];
    int pidx = program_idx[p.first][p.second];
    for(int d = 0; d < 4; ++d) {
        auto lc = last_codel(pidx, PD, CC);
        if(PD == 0) {
            int x = lc.first + 1;
            int y = lc.second;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        else if(PD == 1) {
            int x = lc.first;
            int y = lc.second - 1;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        else if(PD == 2) {
            int x = lc.first - 1;
            int y = lc.second;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        else if(PD == 3) {
            int x = lc.first;
            int y = lc.second + 1;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        
        if(CC == 1) CC = 0;
        else CC = 1;
        
        lc = last_codel(pidx, PD, CC);
        if(PD == 0) {
            int x = lc.first + 1;
            int y = lc.second;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        else if(PD == 1) {
            int x = lc.first;
            int y = lc.second - 1;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        else if(PD == 2) {
            int x = lc.first - 1;
            int y = lc.second;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        else if(PD == 3) {
            int x = lc.first;
            int y = lc.second + 1;
            if(!(x < 1 || x > N || y < 1 || y > M) && (board[x][y] != 'X') && (program_idx[x][y] != pidx)) {
                return {x, y};
            }
        }
        PD = (PD + 1) % 4;
    }
    return {-1, -1};
}

void solve() {
    st = {1, 1};
    int cnt = 0;
    while(true) {
        pii nxt = execute(st);
        if(nxt.first == -1 && nxt.second == -1) break;
        st = nxt;
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin>>N>>M;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cin>>board[i][j];
        }
    }

    indexing();
    // showing();
    solve();

    return 0;
}