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

int N, K;
int q[MAX];
int seq[MAX];
bool invalid;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>K;
    for(int i = 1; i <= N; ++i) cin>>seq[i];
    for(int i = N; i >= 1; --i) {
        int j = 1;
        for(j = 1; j <= K; ++j) {
            if(q[j] == 0 || q[j] > seq[i]) {
                q[j] = seq[i];
                break;
            }
        }
        if(j == K+1) invalid = true;
    }

    if(invalid) cout<<"NO\n";
    else cout<<"YES\n";

	return 0;
}