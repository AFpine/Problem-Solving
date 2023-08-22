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
const int MAX = 1010;

int N;
int uf[MAX];
pll arr[MAX];

int find(int a) {
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    uf[a] += uf[b];
    uf[b] = a;
}

ll dist(int i, int j) {
    return (arr[i].first-arr[j].first) * (arr[i].first-arr[j].first) + (arr[i].second-arr[j].second) * (arr[i].second-arr[j].second);
}

bool solve(ll p) {
    fill(uf, uf+MAX, -1);

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(i == j) continue;

            if(dist(i, j) <= p) merge(i, j);
        }
    }

    int t = find(1);
    bool invalid = false;
    for(int i = 2; i <= N; ++i) {
        if(t != find(i)) invalid = true;
    }

    if(invalid) return false;
    else return true;
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
        cin>>arr[i].first>>arr[i].second;
    }

    ll l = 0, r = 25000LL*25000LL*2LL+1LL;

    ll result = r;
    while(l <= r) {
        ll mid = (l+r)/2LL;

        if(solve(mid)) {
            result = min(result, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout<<result;

	return 0;
}