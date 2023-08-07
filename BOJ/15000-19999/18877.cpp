#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 111;

int N, M;
vector<pll> v;

bool solve(ll p) {
    int cnt = 0;
    ll prv = -INF;
    ll cur = v[0].first;
    for(auto &e : v) {
        while(true) {
            if(cur < e.first) {
                cur = e.first + p;
                cnt++;
            }
            else if(cur >= e.first && cur <= e.second) {
                cur += p;
                cnt++;
            }
            else break;
        }
    }
    if(cnt >= N) return true;
    else return false;
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
    for(int i = 1; i <= M; ++i) {
        ll a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    ll result = 0;
    ll l = 0, r = 1e18;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(solve(mid)) {
            result = max(result, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout<<result;

	return 0;
}