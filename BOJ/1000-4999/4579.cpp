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
const int MAX = 50;

int N;
int a, b;
string s1, s2;
int board[11][11];
bool selected[11][11];
bool exist1[2][11][11];
bool exist2[5][5][11];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pii pos(string s) {
	return {(s[0]-'A'), (s[1]-'1')};
}

bool isvalid(int x, int y, int num) {
	return !exist1[0][x][num] && !exist1[1][y][num] && !exist2[x/3][y/3][num];
}

bool f(int x, int y) {
	if(x == 9) {
		return true;
	}
	if(y == 9) return f(x+1, 0);
	if(board[x][y] != 0) return f(x, y+1);

	for(int i = 1; i <= 9; ++i) {
		if(!isvalid(x, y, i)) continue;

		board[x][y] = i;
		exist1[0][x][i] = true;
		exist1[1][y][i] = true;
		exist2[x/3][y/3][i] = true;

		for(int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx < 0 || nx >= 9 || ny < 0 || ny >= 9 || board[nx][ny] != 0) continue;
			for(int j = 1; j <= 9; ++j) {
				if(!selected[i][j] && isvalid(nx, ny, j)) {
					selected[i][j] = selected[j][i] = true;
					exist1[0][nx][j] = true;
					exist1[1][ny][j] = true;
					exist2[nx/3][ny/3][j] = true;
					board[nx][ny] = j;
					if(f(x, y+1)) return true;
					selected[i][j] = selected[j][i] = false;
					exist1[0][nx][j] = false;
					exist1[1][ny][j] = false;
					exist2[nx/3][ny/3][j] = false;
					board[nx][ny] = 0;
				}
			}
		}

		exist1[0][x][i] = false;
		exist1[1][y][i] = false;
		exist2[x/3][y/3][i] = false;
	}
	
	board[x][y] = 0;
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	while(true) {
		cin>>N;
		if(N == 0) break;

		memset(board, 0, sizeof(board));
		memset(exist1, 0, sizeof(exist1));
		memset(exist2, 0, sizeof(exist2));
		memset(selected, 0, sizeof(selected));

		for(int i = 1; i <= 9; ++i) selected[i][i] = true;

		for(int i = 1; i <= N; ++i) {
			cin>>a>>s1>>b>>s2;

			board[pos(s1).first][pos(s1).second] = a;
			board[pos(s2).first][pos(s2).second] = b;
			selected[a][b] = selected[b][a] = true;

			exist1[0][pos(s1).first][a] = true;
			exist1[1][pos(s1).second][a] = true;
			exist2[pos(s1).first/3][pos(s1).second/3][a] = true;

			exist1[0][pos(s2).first][b] = true;
			exist1[1][pos(s2).second][b] = true;
			exist2[pos(s2).first/3][pos(s2).second/3][b] = true;
		}
		for(int i = 1; i <= 9; ++i) {
			cin>>s1;
			board[pos(s1).first][pos(s1).second] = i;

			exist1[0][pos(s1).first][i] = true;
			exist1[1][pos(s1).second][i] = true;
			exist2[pos(s1).first/3][pos(s1).second/3][i] = true;
		}

		cout<<"Puzzle "<<++t<<'\n';
		f(0, 0);
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) cout<<board[i][j];
			cout<<'\n';
		}
	}

	return 0;
}