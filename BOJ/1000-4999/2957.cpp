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
const int MAX = 303030;

int N;
ll result;
int depth[MAX];
set<int> s;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	s.insert(0);
	s.insert(N+1);
	depth[0] = depth[N+1] = -1;

	for(int i = 1; i <= N; ++i) {
		int t;
		cin>>t;

		s.insert(t);
		auto it = s.find(t);

		depth[t] = max(depth[*(next(it, 1))], depth[*(prev(it, 1))]) + 1;

		result += depth[t];
		cout<<result<<'\n';
	}
	

	return 0;
}