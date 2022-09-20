#include <bits/stdc++.h>

// 5977 Mowing the Lawn

// update 220920

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
const int MAX = 100005;

int N, K, R;
ll arr[MAX], psum[MAX];
ll dp[MAX];
priority_queue<pll> pq;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
	for(int i = 1; i <= N; ++i) psum[i] = arr[i] + psum[i-1];

	pq.push({0, 0});
	for(int i = 1; i <= N; ++i) {
		while(pq.top().second < i-K) pq.pop();
		dp[i] = psum[i] + pq.top().first;
		//Then, dp[i] is max value when select cow[i]
		pq.push({dp[i-1]-psum[i], i});
		//push the value that cow[i] doesn't selected
		dp[i] = max(dp[i], dp[i-1]);
		//compare max(cow[i] selected, cow[i] doesn't selected)
	}
	cout<<dp[N];
}