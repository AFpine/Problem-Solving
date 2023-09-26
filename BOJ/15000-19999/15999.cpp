#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
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
const int MAX = 2020;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
char grid[MAX][MAX];
ll result = 1;
int cnt = 0;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>grid[i][j];
		}
	}

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			bool flag = true;
			for(int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if(x < 1 || x > N || y < 1 || y > M) continue;
				if(grid[x][y] != grid[i][j]) flag = false;
			}
			if(flag) cnt++;
		}
	}
	
	for(int i = 1; i <= cnt; ++i) {
		result = (result * 2LL) % MOD;
	}
	cout<<result;
	
	return 0;
}
