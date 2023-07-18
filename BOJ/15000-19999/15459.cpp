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
const int MAX = 101010;

ll N, M;
ll F[MAX], S[MAX];

bool check(ll p) {
	vector<int> v;
	for(int i = 1; i <= N; ++i) if(S[i] > p) v.push_back(i);
	int prv = 0;
	for(auto &i : v) {
		if((F[i-1] - F[prv]) >= M) return true;
		prv = i;
	}
	if(F[N] - F[prv] >= M) return true;
	return false;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		cin>>F[i]>>S[i];
	}
	for(int i = 1; i <= N; ++i) F[i] += F[i-1];

	ll l = 1, r = 1e18;
	ll result = r+1;
	while(l <= r) {
		auto mid = (l+r)/2LL;
		if(check(mid)) {
			result = min(result, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	cout<<result;

	return 0;
}