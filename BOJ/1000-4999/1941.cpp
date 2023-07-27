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
const int MAX = 1000;

char board[MAX][MAX];
bool visited[MAX][MAX];
pii arr[MAX];
int result;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
map<vector<int>, int> mp;
ll table[8] = {701, 709, 719, 727, 733, 739, 743};

void hashing() {
	vector<int> v;
	for(int i = 1; i <= 7; ++i) v.push_back(arr[i].first * 31 + arr[i].second);
	sort(v.begin(), v.end());

	if(mp[v] == 0) mp[v] = ++result;
	return;
}

void f(int y, int s, int cnt) {
	if(cnt == 7) {
		if(s > y) {
			hashing();
		}
		return;
	}

	for(int c = 1; c <= cnt; ++c) {
		int i = arr[c].first;
		int j = arr[c].second;
		for(int dir = 0; dir < 4; ++dir) {
			int nx = i + dx[dir];
			int ny = j + dy[dir];
			if(nx < 1 || nx > 5 || ny < 1 || ny > 5) continue;
			if(visited[nx][ny]) continue;

			visited[nx][ny] = true;
			arr[cnt+1] = {nx, ny};
			if(board[nx][ny] == 'Y') f(y+1, s, cnt+1);
			else f(y, s+1, cnt+1);
			visited[nx][ny] = false;
		}
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

	for(int i = 1; i <= 5; ++i) {
		for(int j = 1; j <= 5; ++j) {
			cin>>board[i][j];
		}
	}

	for(int i = 1; i <= 5; ++i) {
		for(int j = 1; j <= 5; ++j) {
			arr[1] = {i, j};
			visited[i][j] = true;
			if(board[i][j] == 'Y') f(1, 0, 1);
			else f(0, 1, 1);
			visited[i][j] = false;
		}
	}
	
	cout<<result;

	return 0;
}