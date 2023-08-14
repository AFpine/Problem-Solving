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
const int MAX = 505050;

struct P {
    int x;
    int idx;
    bool operator<(const P& rhs) const {
        if(x == rhs.x) return idx > rhs.idx;
        return x > rhs.x;
    }
};

int N, K;
string S;
bool erased[MAX];
priority_queue<P> pq;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>K;
    cin>>S;
    
    for(int i = 0; i < N; ++i) {
        int cur = S[i] - '0';
        while(!pq.empty() && K > 0) {
            if(pq.top().x >= cur) break;
            else {
                erased[pq.top().idx] = true;
                pq.pop();
                K--;
            }
        }
        pq.push({cur, i});
    }
    while(!pq.empty() && K > 0) {
        erased[pq.top().idx] = true;
        pq.pop();
        K--;
    }

    for(int i = 0; i < N; ++i) {
        if(erased[i] == false) cout<<S[i];
    }

	return 0;
}