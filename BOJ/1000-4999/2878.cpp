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
const int MAX = 101010;

ll M, N;
ll arr[MAX];
ll valid = 2*1e9 + 10LL;
vector<ll> remain;

bool solve(ll p) {
    ll m = M;
    for(int i = 1; i <= N; ++i) {
        ll t = arr[i] - p;
        if(t > 0) m -= t;
    }
    if(m >= 0) return true;
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

    cin>>M>>N;

    for(int i = 1; i <= N; ++i) {
        cin>>arr[i];
    }

    ll l = 0, r = 2*1e9;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(solve(mid)) {
            valid = min(valid, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }

    int cnt = 0;
    for(int i = 1; i <= N; ++i) {
        if(arr[i] <= valid) {
            remain.push_back(arr[i]);
        }
        else {
            remain.push_back(valid);
            M -= (arr[i] - valid);
        }
    }
    sort(remain.begin(), remain.end(), [](ll a, ll b) {
        return a > b;
    });

    ll result = 0;
    for(auto &i : remain) {
        if(M > 0) {
            result += (i-1)*(i-1);
            M--;
        }
        else result += i*i;
    }

    cout<<result;
    
	return 0;
}