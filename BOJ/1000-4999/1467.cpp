#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1467

// 221105

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
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1010;

int N;
string S;
bool selected[MAX];
int remain[10], cnt[10], ans[MAX];
vector<char> A;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>S;
	A.resize(sz(S));
	for(int i = 0; i < sz(S); ++i) {
		A[i] = S[i];
		remain[A[i]-'0']++;
		cnt[A[i]-'0']++;
	}
	N = sz(S);

	cin>>S;
	for(int i = 0; i < sz(S); ++i) {
		remain[S[i]-'0']--;
	}
	N -= sz(S);

	// for(int i = 0; i < 10; ++i) cout<<remain[i]<<" ";

	int st = 0;
	while(N) {
		bool sel = false;
		for(int j = 9; j >= 0; --j) {
			if(sel) break;
			if(!remain[j]) continue;
			for(int k = st; k < sz(A); ++k) {
				fill(cnt, cnt+10, 0);
				if(A[k]-'0' == j) {
					for(int l = k; l < sz(A); ++l) {
						cnt[A[l]-'0']++;
					}
					bool flag = false;
					for(int l = 0; l < 10; ++l) {
						if(cnt[l] < remain[l]) flag = true;
					}
					if(flag) continue;
					remain[j]--;
					ans[k] = j;
					selected[k] = true;
					st = k+1;
					N--;
					sel = true;
					break;
				}
			}
		}
	}

	for(int i = 0; i < MAX; ++i) {
		if(selected[i]) cout<<ans[i];
	}


	return 0;
}
