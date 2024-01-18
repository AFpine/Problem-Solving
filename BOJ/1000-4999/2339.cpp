#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

int N;
int board[25][25];
ll ans = 0;

int isvalid(int sx, int sy, int ex, int ey) {
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = sx; i <= ex; ++i) {
		for(int j = sy; j <= ey; ++j) {
			if(board[i][j] == 1) cnt1++;
			else if(board[i][j] == 2) cnt2++;
		}
	}
	if(cnt1 == 0 && cnt2 == 1) return 1;
	else return 0;
}

ll cut(int sx, int sy, int ex, int ey, int flag) {
	if((sx > ex) || (sy > ey)) return 0;

	int valid = isvalid(sx, sy, ex, ey);
	if(valid == 1) {
		// cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<"\n";
		return 1;
	}

	ll ret = 0;

	if(flag == 0) {
		for(int y = sy; y <= ey; ++y) {
			ll cur = 0;
			int cnt1 = 0;
			int cnt2 = 0;
			for(int x = sx; x <= ex; ++x) {
				if(board[x][y] == 1) cnt1++;
				else if(board[x][y] == 2) cnt2++;
			}
			if((cnt1 > 0) && (cnt2 == 0)) cur = cut(sx, sy, ex, y-1, 1) * cut(sx, y+1, ex, ey, 1);
			else cur = 0;

			ret += cur;
		}
	}
	else {
		for(int x = sx; x <= ex; ++x) {
			ll cur = 0;
			int cnt1 = 0;
			int cnt2 = 0;
			for(int y = sy; y <= ey; ++y) {
				if(board[x][y] == 1) cnt1++;
				else if(board[x][y] == 2) cnt2++;
			}
			if((cnt1 > 0) && (cnt2 == 0)) cur = cut(sx, sy, x-1, ey, 0) * cut(x+1, sy, ex, ey, 0);
			else cur = 0;
			
			ret += cur;
		}
	}

	return ret;
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

	if(isvalid(1, 1, N, N) == 1) {
		cout<<"1";
		return 0;
	}

	ans += cut(1, 1, N, N, 0);
	ans += cut(1, 1, N, N, 1);

	if(ans == 0) cout<<"-1";
	else cout<<ans;
	
	return 0;
}