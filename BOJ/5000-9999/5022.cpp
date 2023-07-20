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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N, M;
pii A[2], B[2];
int dist[MAX][MAX];
bool visited[MAX][MAX];
pii prv[MAX][MAX];
int result = INF;

void solve(pii fr[2], pii sc[2]) {
	int res = 0;
	memset(dist, -1, sizeof(dist));
	for(int i = 0; i <= N; ++i) for(int j = 0; j <= M; ++j) prv[i][j] = {-1, -1};
	memset(visited, false, sizeof(visited));
	queue<pii> Q;

	dist[fr[0].first][fr[0].second] = 0;
	visited[fr[0].first][fr[0].second] = true;
	visited[sc[0].first][sc[0].second] = visited[sc[1].first][sc[1].second] = true;
	Q.push(fr[0]);
	
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if(cur == fr[1]) break;

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];
			if(x < 0 || x > N || y < 0 || y > M) continue;
			if(visited[x][y]) continue;

			dist[x][y] = dist[cur.first][cur.second] + 1;
			visited[x][y] = true;
			prv[x][y] = cur;
			Q.push({x, y});
		}
	}
	
	res += dist[fr[1].first][fr[1].second];

	memset(visited, false, sizeof(visited));
	auto t = fr[1];
	while(t != pii(-1, -1)) {
		visited[t.first][t.second] = true;
		t = prv[t.first][t.second];
	}

	memset(dist, -1, sizeof(dist));
	while(!Q.empty()) Q.pop();

	dist[sc[0].first][sc[0].second] = 0;
	visited[sc[0].first][sc[0].second] = true;
	Q.push(sc[0]);
	
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if(cur == sc[1]) break;

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];
			if(x < 0 || x > N || y < 0 || y > M) continue;
			if(visited[x][y]) continue;

			dist[x][y] = dist[cur.first][cur.second] + 1;
			visited[x][y] = true;
			Q.push({x, y});
		}
	}

	if(dist[sc[1].first][sc[1].second] == -1) return;
	else {
		result = min(result, res + dist[sc[1].first][sc[1].second]);
		return;
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

	cin>>N>>M;
	cin>>A[0].first>>A[0].second;
	cin>>A[1].first>>A[1].second;
	cin>>B[0].first>>B[0].second;
	cin>>B[1].first>>B[1].second;

	solve(A, B);
	solve(B, A);

	if(result == INF) {
		cout<<"IMPOSSIBLE";
	}
	else cout<<result;

	return 0;
}