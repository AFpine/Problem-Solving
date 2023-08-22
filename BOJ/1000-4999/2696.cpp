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
const long long MOD = 1000000LL;
const int MAX = 10101;

int flag;
struct Seg {
    vector<ll> t;
    void build(int n) {
        for(flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void add(int p, ll value) {
        for (t[p += flag - 1] += value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
    }
    ll kth(ll k, int n = 1) {
        assert(t[n] >= k);
        if (flag <= n) return n - flag + 1;
        if (k <= t[n << 1]) return kth(k, n << 1);
        else return kth(k - t[n << 1], n << 1 | 1);
    }
}seg;

int M;
ll arr[MAX];
vector<ll> v;
map<ll, ll> mp;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin>>T;
    for(int tt = 0; tt < T; ++tt) {
        if(tt > 0) cout<<'\n';
        v.clear();
        mp.clear();
        v.push_back(-llINF);
        
        Seg seg;
        seg.build(MAX);

        cin>>M;
        for(int i = 1; i <= M; ++i) {
            cin>>arr[i];
            v.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for(int i = 1; i <= M; ++i) {
            ll t = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            mp[t] = arr[i];
            arr[i] = t;
        }

        int cnt = 0;
        cout<<M/2+1<<'\n';
        for(int i = 1; i <= M; ++i) {
            seg.add(arr[i], 1);
            if(i % 2) {
                cnt++;
                if(cnt > 10 && cnt % 10 == 1) cout<<'\n';
                cout<<mp[seg.kth(i/2+1)]<<" ";
            }
        }
    }

	return 0;
}
