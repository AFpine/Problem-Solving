// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const long long MOD = 998244353;
const int MAX = 505050;

int N;
int pre[MAX], preidx[MAX], post[MAX], postidx[MAX];
ll answer = 1;
bool invalid = false;

void solve(int l1, int r1, int l2, int r2) {
	if(l1 == r1 && l2 == r2) return;

	int root = pre[l1];
	int ridx = postidx[root];

	if(ridx != r2) {
		invalid = true;
		return;
	}
	root = pre[l1+1];
	ridx = postidx[root];

	if(ridx > r2 || ridx < l2) {
		invalid = true;
		return;
	}

	if(ridx == r2-1) {
		answer = (answer * 2LL) % MOD;
		solve(l1+1, r1, l2, ridx);
	}
	else {
		int t = ridx - l2 + 1;
		solve(l1+1, l1+t, l2, ridx);
		solve(l1+t+1, r1, ridx+1, r2-1);
	}
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
		cin>>pre[i];
		preidx[pre[i]] = i;
	}
	for(int i = 1; i <= N; ++i) {
		cin>>post[i];
		postidx[post[i]] = i;
	}

	solve(1, N, 1, N);

	if(invalid) cout<<"0";
	else cout<<answer;

	return 0;
}
