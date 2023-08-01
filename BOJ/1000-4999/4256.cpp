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
const long long MOD = 1e9+7;
const int MAX = 1010;

int T, N;
int pre[MAX], in[MAX];

// inorder tree로 순회
// 출력은 preorder tree 사용
void f(int idx, int l, int r) {
	if(l > r) return;
	if(l == r) {
		cout<<pre[idx]<<" ";
		return;
	}

	int p = in[pre[idx]];
	f(idx+1, l, p-1);
	f(idx+p-l+1, p+1, r);
	cout<<pre[idx]<<" ";
	return;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--) {
		cin>>N;
		for(int i = 1; i <= N; ++i) cin>>pre[i];
		for(int i = 1; i <= N; ++i) {
			int t;
			cin>>t;
			in[t] = i;
		}

		f(1, 1, N);
		cout<<'\n';
	}
	

	return 0;
}