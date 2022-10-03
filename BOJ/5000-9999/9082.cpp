#include <bits/stdc++.h>

// 9082 지뢰찾기

// update 221003

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
const int MAX = 105;

int N, num[MAX];
char c[MAX];
ll ans;

void greedysetmine(int idx) {
	if(idx == 1 && num[idx] && num[idx+1]) {
		num[idx]--;
		num[idx+1]--;
		ans++;
	}
	else if(idx == N && num[idx] && num[idx-1]) {
		num[idx]--;
		num[idx-1]--;
		ans++;
	}
	else if(num[idx-1] && num[idx] && num[idx+1]) {
		num[idx]--;
		num[idx-1]--;
		num[idx+1]--;
		ans++;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin>>tc;
	while(tc--) {
		ans = 0;

		cin>>N;

		for(int i = 1; i <= N; ++i) {
			char t;
			cin>>t;
			num[i] = t-'0';
		}
		for(int i = 1; i <= N; ++i) cin>>c[i];

		for(int i = 1; i <= N; ++i) {
			greedysetmine(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}