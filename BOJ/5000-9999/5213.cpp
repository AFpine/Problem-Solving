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
const int MAX = 555;

int N;
pii val[MAX][MAX];
int dist[MAX][MAX], prv[MAX*MAX];
int dx[] = {0, 0, 1, 1, -1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, -1, 0, -1, 0, 1, 0, 1};

int idx(int i, int j) {
	int t = i-1;
	int ret = 0;
	ret += N * (t/2);
	ret += (N-1) * (t/2);
	if(t % 2) ret += N;
	return ret + j;
}

bool isValid(int i, int j) {
	if(i < 1 || i > N || j < 1 || j > N) return false;
	if((i % 2 == 0) && j == N) return false;
	return true;
}

void solve() {
	memset(dist, -1, sizeof(dist));
	queue<pii> Q;
	prv[idx(1, 1)] = -1;
	dist[1][1] = 0;
	Q.push({1, 1});

	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if(cur.first % 2) {
			for(int dir = 0; dir < 6; ++dir) {
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];
				
				if(!isValid(x, y)) continue;
				if(dist[x][y] != -1) continue;
				if((dir == 0 || dir == 2 || dir == 4) && val[cur.first][cur.second].second == val[x][y].first) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					prv[idx(x, y)] = idx(cur.first, cur.second);
					Q.push({x, y});
				}
				else if((dir == 1 || dir == 3 || dir == 5) && val[cur.first][cur.second].first == val[x][y].second) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					prv[idx(x, y)] = idx(cur.first, cur.second);
					Q.push({x, y});
				}
			}
		}
		else {
			for(int dir = 0; dir < 2; ++dir) {
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];
				
				if(!isValid(x, y)) continue;
				if(dist[x][y] != -1) continue;
				if(dir == 0 && val[cur.first][cur.second].second == val[x][y].first) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					prv[idx(x, y)] = idx(cur.first, cur.second);
					Q.push({x, y});
				}
				else if(dir == 1 && val[cur.first][cur.second].first == val[x][y].second) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					prv[idx(x, y)] = idx(cur.first, cur.second);
					Q.push({x, y});
				}
			}
			for(int dir = 6; dir < 10; ++dir) {
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];
				
				if(!isValid(x, y)) continue;
				if(dist[x][y] != -1) continue;
				if((dir == 6 || dir == 8) && val[cur.first][cur.second].first == val[x][y].second) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					prv[idx(x, y)] = idx(cur.first, cur.second);
					Q.push({x, y});
				}
				else if((dir == 7 || dir == 9) && val[cur.first][cur.second].second == val[x][y].first) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					prv[idx(x, y)] = idx(cur.first, cur.second);
					Q.push({x, y});
				}
			}
		}
	}

	vector<int> result;
	for(int i = N; i >= 1; --i) {
		int t = N-1;
		if(i % 2) t = N;
		for(int j = t; j >= 1; --j) {
			if(dist[i][j] >= 0) {
				cout<<dist[i][j]+1<<'\n';
				int p = idx(i, j);
				while(p > 0) {
					result.push_back(p);
					p = prv[p];
				}
				reverse(result.begin(), result.end());
				for(auto &i : result) cout<<i<<" ";
				return;
			}
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

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		int t = N-1;
		if(i % 2) t = N;
		for(int j = 1; j <= t; ++j) {
			cin>>val[i][j].first>>val[i][j].second;
		}
	}

	solve();

	return 0;
}