#include <bits/stdc++.h>

// 9426 중앙값 측정

// 221015

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
const int MAX = 252525;
const int segMAX = 65550;
 
int N, K, temp[MAX];
ll tree[4*segMAX];

void update(int s, int e, int node, int pos, int k) {
    if(pos > e || pos < s) return;
    if(s == e) {
        tree[node] += k;
        return;
    }
    int mid = (s+e)/2;
    update(s, mid, node*2, pos, k);
    update(mid+1, e, node*2+1, pos, k);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int l, int r) {
    if(l > e || r < s) return 0;
    if(l <= s && r >= e) return tree[node];
    int mid = (s+e)/2;
    return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
    int pivot = ((K+1)/2);
    for(int i = 1; i <= N; ++i) cin>>temp[i];

    ll ans = 0;
    for(int i = 1; i <= N; ++i) {
        if(i > K) update(0, segMAX, 1, temp[i-K], -1);
        update(0, segMAX, 1, temp[i], 1);
        if(i >= K) {
            int tmp;
            int l = 0, r = 65535;
            while(l <= r) {
                int mid = (l+r)/2;
                if(query(0, segMAX, 1, 0, mid) >= pivot) {
                    tmp = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            // cout<<tmp<<" "<<query(0, segMAX, 1, 0, tmp)<<"\n";
            ans += tmp;
        }
    }
    cout<<ans;
	return 0;
}