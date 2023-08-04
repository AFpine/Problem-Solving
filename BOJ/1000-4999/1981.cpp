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
const int MAX = 111;

int N;
int board[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool solve(int low, int upp) {
    if(board[1][1] > upp || board[1][1] < low) return false;
    
    memset(visited, false, sizeof(visited));
    visited[1][1] = true;

    queue<pii> Q;
    Q.push({1, 1});

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir) {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            if(x < 1 || x > N || y < 1 || y > N) continue;
            if(visited[x][y]) continue;
            if(board[x][y] > upp || board[x][y] < low) continue;
            visited[x][y] = true;
            Q.push({x, y});
        }
    }
    if(visited[N][N]) return true;
    else return false;
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
        for(int j = 1; j <= N; ++j) {
            cin>>board[i][j];
        }
    }

    int result = 202;
    int l = 0, r = 201;
    while(l <= r) {
        int mid = (l+r)/2;
        bool valid = false;
        for(int i = 0; i <= 200; ++i) {
            int j = i + mid;
            if(j > 200) break;
            if(solve(i, j)) {
                valid = true;
                break;
            }
        }
        if(valid) {
            result = min(result, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout<<result;

	return 0;
}