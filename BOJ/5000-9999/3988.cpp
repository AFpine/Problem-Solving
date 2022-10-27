#include <bits/stdc++.h>

// 3988

// 221027

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
const int MAX = 1010101;

int N, K;
int arr[MAX];
multiset<int> ms;

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
	
	sort(arr+1, arr+1+N);

	for(int i = 1; i < N-K; ++i) ms.insert(abs(arr[i] - arr[i+1]));

	int ans = (*ms.begin()) + abs(arr[N-K] - arr[1]);

	int l = 2;
	for(int r = N-K+1; r <= N; ++r, l++) {
		auto it = ms.find(abs(arr[l]-arr[l-1]));
		ms.erase(it);
		ms.insert(abs(arr[r]-arr[r-1]));

		ans = min(ans, (*ms.begin()) + abs(arr[r] - arr[l]));
	}

	cout<<ans;

	return 0;
}