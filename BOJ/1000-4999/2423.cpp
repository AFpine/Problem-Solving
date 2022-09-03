// #define LOCAL_TEST

#include <bits/stdc++.h>

// 2423 전구를 켜라

// update 220902

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
const long long MOD = 1000000007;
const int MAX = 505;

struct DK {
	pii pos;
	int weight;	
	bool operator< (const DK& rhs) const {
		return weight > rhs.weight;
	}
};

int N, M;
int board[MAX][MAX];
int dist[MAX][MAX];
int w[MAX][MAX];

int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

void input() {
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			char c;
			cin>>c;
			if(c == '/') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
}

void solve() {
	if((N % 2) ^ (M % 2)) { cout<<"NO SOLUTION"; return; }

	for(int i = 1; i <= N; ++i) {
		int p;
		if(i % 2) p = 0;
		else p = 1;

		for(int j = 1; j <= M; ++j) {
			if(board[i][j] != p) w[i][j] = 1;
			else w[i][j] = 0;
			p ^= 1;
		}
	}

	// for(int i = 1; i <= N; ++i) {
	// 	for(int j = 1; j <= M; ++j) {
	// 		cout<<w[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }

	priority_queue<DK> pq;
	dist[1][1] = w[1][1];
	pq.push({{1, 1}, dist[1][1]});
	memset(dist, INF, sizeof(dist));

	while(!pq.empty()) {
		auto pos = pq.top().pos;
		auto weight = pq.top().weight;
		pq.pop();

		if(weight > dist[pos.first][pos.second]) continue;

		for(int dir = 0; dir < 8; ++dir) {
			int x = pos.first + dx[dir];
			int y = pos.second + dy[dir];
			if(x < 1 || x > N || y < 1 || y > M) continue;
			if((pos.first + pos.second) % 2) {
				if(dir == 4 || dir == 5) continue;
			}
			else {
				if(dir == 6 || dir == 7) continue;
			}
			if(dist[x][y] > weight + w[x][y]) {
				dist[x][y] = weight + w[x][y];
				pq.push({{x, y}, dist[x][y]});
			}
		}
	}

	cout<<dist[N][M];
}

int main() {

	#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}