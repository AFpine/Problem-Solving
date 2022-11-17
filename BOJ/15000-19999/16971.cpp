#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 16971

// 221117

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const ll MOD = 1e9+7;
const int MAX = 1010;

ll N, M, arr[MAX][MAX], rsum[MAX], csum[MAX];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>arr[i][j];
			if((i == 1 || i == N) && (j == 1 || j == M)) {
				rsum[i] += arr[i][j];
				csum[j] += arr[i][j];
			}
			else if(i != 1 && i != N && j != 1 && j != M) {
				rsum[i] += 4LL*arr[i][j];
				csum[j] += 4LL*arr[i][j];
			}
			else {
				rsum[i] += 2LL*arr[i][j];
				csum[j] += 2LL*arr[i][j];
			}
		}
	}

	ll rmx = max(2LL*rsum[1], 2LL*rsum[N]);
	ll cmx = max(2LL*csum[1], 2LL*csum[M]);
	ll Ridx = (rsum[1] > rsum[N]) ? 1 : N;
	ll Cidx = (csum[1] > csum[M]) ? 1 : M;
	ll rmn = INF, cmn = INF, ridx = 0, cidx = 0;

	for(int i = 2; i < N; ++i) {
		if(rmn > rsum[i]) {
			rmn = rsum[i];
			ridx = i;
		} 
	}
	for(int i = 2; i < M; ++i) {
		if(cmn > csum[i]) {
			cmn = csum[i];
			cidx = i;
		}
	}
	
	if((rmx > rmn) && (cmx > cmn)) {
		if((rmx-rmn) > (cmx-cmn)) {
			for(int i = 1; i <= M; ++i) swap(arr[Ridx][i], arr[ridx][i]);
		}
		else {
			for(int i = 1; i <= N; ++i) swap(arr[i][Cidx], arr[i][cidx]);
		}
	}
	else if(rmx > rmn) {
		for(int i = 1; i <= M; ++i) swap(arr[Ridx][i], arr[ridx][i]);
	}
	else if(cmx > cmn) {
		for(int i = 1; i <= N; ++i) swap(arr[i][Cidx], arr[i][cidx]);
	}

	ll ans = 0;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if((i == 1 || i == N) && (j == 1 || j == M)) ans += arr[i][j];
			else if(i != 1 && i != N && j != 1 && j != M) ans += 4LL*arr[i][j];
			else ans += 2LL*arr[i][j];
			// cout<<arr[i][j]<<" ";
		}
		// cout<<'\n';
	}

	cout<<ans<<'\n';

	// cout<<rmx<<" "<<rmn<<" "<<cmx<<" "<<cmn;

	return 0;
}