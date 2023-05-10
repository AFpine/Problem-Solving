#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
// typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 15;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int N, result1, result2;
int board[MAX][MAX];
bool rd[25], ld[25];

void f1(int r, int c, int cnt) {
	if(c > N) {
		r += 1;
		if(c % 2 == 0) c = 1;
		else c = 2;
	}
	if(r > N) {
		result1 = max(result1, cnt);
		return;
	}
	if(board[r][c] && !rd[r+c] && !ld[N-c+1+r]) {
		rd[r+c] = ld[N-c+1+r] = true;
		f1(r, c+2, cnt+1);
		rd[r+c] = ld[N-c+1+r] = false;
	}
	f1(r, c+2, cnt);
}

void f2(int r, int c, int cnt) {
	if(c > N) {
		r += 1;
		if(c % 2 == 0) c = 1;
		else c = 2;
	}
	if(r > N) {
		result2 = max(result2, cnt);
		return;
	}
	if(board[r][c] && !rd[r+c] && !ld[N-c+1+r]) {
		rd[r+c] = ld[N-c+1+r] = true;
		f2(r, c+2, cnt+1);
		rd[r+c] = ld[N-c+1+r] = false;
	}
	f2(r, c+2, cnt);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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

	f1(1, 1, 0);
	f2(1, 2, 0);

	cout<<result1+result2;

	return 0;
}