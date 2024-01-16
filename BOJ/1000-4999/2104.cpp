#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

int N;
ll arr[101010];
ll psum[101010];

ll histogram(int s, int e) {
	if(s > e) return 0;
	if(s == e) return arr[s] * arr[s];

	int mid = (s + e) / 2;
	ll ret = max(histogram(s, mid), histogram(mid+1, e));

	int l, r;
	l = r = mid;
	ll mn = arr[mid];
	ll cur = arr[mid] * arr[mid];
	while(true) {
		if(l == s && r == e) break;
		else if(l == s) {
			mn = min(mn, arr[r+1]);
			cur = max(cur, ((psum[r+1] - psum[l-1]) * mn));
			r++;
		}
		else if(r == e) {
			mn = min(mn, arr[l-1]);
			cur = max(cur, ((psum[r] - psum[l-2]) * mn));
			l--;
		}
		else {
			if(arr[l-1] < arr[r+1]) {
				mn = min(mn, arr[r+1]);
				cur = max(cur, ((psum[r+1] - psum[l-1]) * mn));
				r++;
			}
			else {
				mn = min(mn, arr[l-1]);
				cur = max(cur, ((psum[r] - psum[l-2]) * mn));
				l--;
			}
		}
	}
	return max(ret, cur);
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
		cin>>arr[i];
		psum[i] = arr[i] + psum[i-1];
	}

	cout<<histogram(1, N);

	return 0;
}