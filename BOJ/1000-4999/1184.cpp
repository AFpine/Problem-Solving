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
const int MAX = 55;

int N;
int psum[MAX][MAX];
unordered_map<int, int> mp;
ll result;

int val(int i, int j, int k, int l) {
	return psum[k][l] - psum[k][j-1] - psum[i-1][l] + psum[i-1][j-1];
}

void f1(int x, int y) {
	mp.clear();
	for(int i = 1; i <= x; ++i) {
		for(int j = 1; j <= y; ++j) {
			mp[val(i, j, x, y)]++;
		}
	}
	for(int i = x + 1; i <= N; ++i) {
		for(int j = y + 1; j <= N; ++j) {
			result += mp[val(x+1, y+1, i, j)];
		}
	}
}
void f2(int x, int y) {
	mp.clear();
	for(int i = 1; i <= x; ++i) {
		for(int j = y; j <= N; ++j) {
			mp[val(i, y, x, j)]++;
		}
	}
	for(int i = x + 1; i <= N; ++i) {
		for(int j = 1; j < y; ++j) {
			result += mp[val(x+1, j, i, y-1)];
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
		for(int j = 1; j <= N; ++j) {
			cin>>psum[i][j];
			psum[i][j] += psum[i][j-1];
		}
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			psum[j][i] += psum[j-1][i];
		}
	}

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			f1(i, j);
			f2(i, j);
		}
	}
	cout<<result;
	
	return 0;
}