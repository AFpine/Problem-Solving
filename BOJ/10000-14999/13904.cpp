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

int N;
pii arr[1010];
int schedule[1010];
int ans;

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
		cin>>arr[i].first>>arr[i].second;
	}

	sort(arr+1, arr+1+N, [](pii a, pii b) {
		return a.second > b.second;
	});

	for(int i = 1; i <= N; ++i) {
		for(int j = arr[i].first; j >= 1; --j) {
			if(schedule[j] == 0) {
				schedule[j] = arr[i].second;
				break;
			}
		}
	}
	
	for(int i = 1; i <= 1000; ++i) {
		ans += schedule[i];
	}
	cout<<ans;

	return 0;
}