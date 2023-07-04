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
const int MAX = 111;

int N, coin[MAX], cnt[MAX], sum;
int dp[MAX][101010];

int f(int idx, int cost) {
	if(idx == N+1) {
		if(cost == (sum/2)) return 1;
		else return 0;
	}
	if(cost > (sum/2)) return 0;

	auto &ret = dp[idx][cost];
	if(ret != -1) return ret;

	ret = 0;
	ret |= f(idx+1, cost);
	for(int i = 1; i <= cnt[idx]; ++i) {
		ret |= f(idx+1, (cost + (coin[idx]*i)));
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

	for(int tt = 1; tt <= 3; ++tt) {
		memset(dp, -1, sizeof(dp));
		sum = 0;

		cin>>N;
		for(int i = 1; i <= N; ++i) {
			cin>>coin[i];
			cin>>cnt[i];
			sum += (coin[i] * cnt[i]);
		}

		if(sum % 2) {
			cout<<"0"<<'\n';
			continue;
		}
		
		int result = f(1, 0);
		if(result > 0) cout<<"1"<<'\n';
		else cout<<"0"<<'\n';
	}

	return 0;
}