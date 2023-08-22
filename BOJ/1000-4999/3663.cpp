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
const int MAX = 22;

int N;
string S;
vector<int> v;

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
    while(T--) {
        v.clear();
        cin>>S;
        N = S.length();

        int ans1 = 0;
        for(int i = 0; i < N; ++i) {
            if(S[i] != 'A') {
                v.push_back(i);
                ans1 += min(abs(S[i] - 'A'), 26 - abs(S[i] - 'A'));
            }
        }

        if(v.empty()) {
            cout<<ans1<<'\n';
            continue;
        }
        
        int res = INF;
        int vs = sz(v);
        for(int i = 0; i < vs-1; ++i) {
            res = min(res, ans1 + 2*v[i] + N-v[i+1]);
            res = min(res, ans1 + 2*N - 2*v[i+1] + v[i]);
        }
        res = min(res, ans1 + N - v[0]);
        res = min(res, ans1 + v[vs-1]);

        cout<<res<<"\n";
    }
    

	return 0;
}