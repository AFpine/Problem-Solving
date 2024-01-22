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

const int MAX = 1010;

int N;
pii arr[MAX];
vector<pii> l, r;


int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i].first>>arr[i].second;
	
	sort(arr+1, arr+1+N, [](pii a, pii b) {
		return a.first < b.first;
	});

	int prv = -1;
	for(int i = 1; i <= N; ++i) {
		if(arr[i].second > prv) {
			prv = arr[i].second;
			l.push_back({ arr[i].first, arr[i].second }); 
		}
	}
	prv = -1;
	for(int i = N; i >= 1; --i) {
		if(arr[i].second > prv) {
			prv = arr[i].second;
			r.push_back({ arr[i].first, arr[i].second }); 
		}
	}
	
	int ans = 0;
	pii prv2 = { 0, 0 };
	for(auto &i : l) {
		ans += (i.first - prv2.first) * prv2.second;
		prv2 = i;
	}
	prv2 = { 0, 0 };
	for(auto &i : r) {
		ans += (prv2.first - i.first) * prv2.second;
		prv2 = i;
	}
	ans += (r.back().first - l.back().first + 1) * l.back().second;

	cout<<ans;

	return 0;
}