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
const long long MOD = 1e9+9;
const int MAX = 1010101;

int xpsum[10], ypsum[10], board[10][10];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 3;
	while(T--) {
		memset(board, 0, sizeof(board));
		fill(xpsum, xpsum+10, 0);
		fill(ypsum, ypsum+10, 0);

		for(int i = 1; i <= 6; ++i) {
			for(int j = 1; j <= 6; ++j) {
				cin>>board[i][j];
				xpsum[i] += board[i][j];
				ypsum[j] += board[i][j];
			}
		}

		int xmx = 0, ymx = 0;
		for(int i = 1; i <= 6; ++i) {
			xmx = max(xmx, xpsum[i]);
			ymx = max(ymx, ypsum[i]);
		}

		if(ymx >= 5 || xmx >= 5) {
			cout<<"no\n";
			continue;
		}

		if(xmx == 2 && ymx == 2) {
			cout<<"yes\n";
			continue;
		}

		if(xmx == 4) {
			int idx;
			for(int i = 1; i <= 6; ++i) if(xpsum[i] == 4) idx = i;
			
			if(xpsum[idx-1] == 1 && xpsum[idx+1] == 1) {
				cout<<"yes\n";
				continue;
			}
		}
		else if(ymx == 4) {
			int idx;
			for(int i = 1; i <= 6; ++i) if(ypsum[i] == 4) idx = i;
			
			if(ypsum[idx-1] == 1 && ypsum[idx+1] == 1) {
				cout<<"yes\n";
				continue;
			}
		}
		else { 
			pii idx = {0, 0};
			for(int i = 2; i <= 5; ++i) {
				if(xpsum[i-1] == 2 && xpsum[i] == 3 && xpsum[i+1] == 1) {
					idx.first = i;
					idx.second = i-1;
					break;
				}
			}
			if(idx != pii(0, 0)) {
				int cnt = 0;
				for(int i = 1; i <= 6; ++i) {
					if(board[idx.first][i] == 1 && board[idx.second][i] == 1) cnt++;
				}
				if(cnt == 1) {
					cout<<"yes\n";
					continue;
				}
				else {
					cout<<"no\n";
					continue;
				}
			}
			for(int i = 2; i <= 5; ++i) {
				if(xpsum[i+1] == 2 && xpsum[i] == 3 && xpsum[i-1] == 1) {
					idx.first = i;
					idx.second = i+1;
					break;
				}
			}
			if(idx != pii(0, 0)) {
				int cnt = 0;
				for(int i = 1; i <= 6; ++i) {
					if(board[idx.first][i] == 1 && board[idx.second][i] == 1) cnt++;
				}
				if(cnt == 1) {
					cout<<"yes\n";
					continue;
				}
				else {
					cout<<"no\n";
					continue;
				}
			}

			for(int i = 2; i <= 5; ++i) {
				if(ypsum[i-1] == 2 && ypsum[i] == 3 && ypsum[i+1] == 1) {
					idx.first = i;
					idx.second = i-1;
					break;
				}
			}
			if(idx != pii(0, 0)) {
				int cnt = 0;
				for(int i = 1; i <= 6; ++i) {
					if(board[i][idx.first] == 1 && board[i][idx.second] == 1) cnt++;
				}
				if(cnt == 1) {
					cout<<"yes\n";
					continue;
				}
				else {
					cout<<"no\n";
					continue;
				}
			}
			for(int i = 2; i <= 5; ++i) {
				if(ypsum[i+1] == 2 && ypsum[i] == 3 && ypsum[i-1] == 1) {
					idx.first = i;
					idx.second = i+1;
					break;
				}
			}
			if(idx != pii(0, 0)) {
				int cnt = 0;
				for(int i = 1; i <= 6; ++i) {
					if(board[i][idx.first] == 1 && board[i][idx.second] == 1) cnt++;
				}
				if(cnt == 1) {
					cout<<"yes\n";
					continue;
				}
				else {
					cout<<"no\n";
					continue;
				}
			}

			for(int i = 1; i <= 5; ++i) {
				if(xpsum[i] == 3 && xpsum[i+1] == 3) {
					idx.first = i;
					idx.second = i+1;
					break;
				}
			}
			if(idx != pii(0, 0)) {
				int cnt = 0;
				for(int i = 1; i <= 6; ++i) {
					if(board[idx.first][i] == 1 && board[idx.second][i] == 1) cnt++;
				}
				if(cnt == 1) {
					cout<<"yes\n";
					continue;
				}
				else {
					cout<<"no\n";
					continue;
				}
			}

			for(int i = 1; i <= 5; ++i) {
				if(ypsum[i] == 3 && ypsum[i+1] == 3) {
					idx.first = i;
					idx.second = i+1;
					break;
				}
			}
			if(idx != pii(0, 0)) {
				int cnt = 0;
				for(int i = 1; i <= 6; ++i) {
					if(board[i][idx.first] == 1 && board[i][idx.second] == 1) cnt++;
				}
				if(cnt == 1) {
					cout<<"yes\n";
					continue;
				}
				else {
					cout<<"no\n";
					continue;
				}
			}
		}

		cout<<"no\n";
	}
	

	return 0;
}