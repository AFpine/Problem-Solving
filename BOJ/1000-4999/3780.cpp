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
const int MAX = 20202;

int T, N;
int uf[MAX], ans[MAX];

int find(int a) {
	if(uf[a] < 0) return a;
	int ret = find(uf[a]);
	ans[a] += ans[uf[a]];
	return uf[a] = ret;
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
		fill(uf, uf+MAX, -1);
		fill(ans, ans+MAX, 0);
		
		cin>>N;
		while(true) {
			char c;
			cin>>c;
			if(c == 'E') {
				int a;
				cin>>a;
				find(a);
				cout<<ans[a]<<'\n';
			}
			else if(c == 'I'){
				// a는 cluster를 제공하는 center이다. 즉, 어떤 cluster를 대표하는 값이다.
				// 그러므로, a로 주어진 값은 다시 나올 수 없다.
				// uf[a]의 갱신은 한 번만 이루어진다.
				int a, b;
				cin>>a>>b;
				ans[a] = abs(a-b) % 1000;
				uf[a] = b;
			}
			else break;
		}
	}
	
	return 0;
}