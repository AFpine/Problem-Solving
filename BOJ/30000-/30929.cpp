#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 505050;

ll N, C, P, Q;
string S;
ll psum[MAX];
int ans = 0;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>N>>C>>P>>Q;
	cin>>S;

	for(int i = 1; i <= N; ++i) {
		psum[i] = (S[i-1] == 'Y' ? 1 : 0) + psum[i-1];
	}

	ll prv = 1;
	for(int i = 1; i <= N; ++i) {
		if((i - C + 1) < 1) continue;

		for(int s = i - C + 1; s >= max((i - C + 1)-4*C, prv); --s) {
			if(((psum[i] - psum[s-1]) * Q) >= (P * ((ll)i - s + 1))) {
				ans++;
				// cout<<i<<" ";
				prv = i+1;
				break;
			}
		}
	}
	// cout<<'\n';
	cout<<ans;	

	return 0;
}