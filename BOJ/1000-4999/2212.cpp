#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

int N, K;
int arr[10101];
ll ans;
priority_queue<int> pq;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
	}
	
	sort(arr+1, arr+1+N);
	
	for(int i = 2; i <= N; ++i) {
		ans += (arr[i] - arr[i-1]);
		pq.push(arr[i] - arr[i-1]);
	}

	int k = 1;
	while(!pq.empty() && k < K) {
		ans -= pq.top();
		pq.pop();
		k++;
	}

	cout<<ans;

	return 0;
}