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
const int MAX = 101010;

int C, N;
int arr[MAX];
int cnt[6];
bool valid[6];

void solve() {
    int t = 7;
    int prvt = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 2;
    arr[7] = 3;

    cnt[1] = 1;
    cnt[2] = 2;
    cnt[3] = 2;
    cnt[4] = 1;
    cnt[5] = 1;

    for(int i = 2; i <= 100; ++i) {
        if(t > 10000) break;
        int pr1 = (i-1)*6, pr2 = 1;
        prvt += (i-2)*6;

        for(int j = 1; j <= i*6; ++j) {
            fill(valid, valid+6, true);
            if(j == i*6) {
                valid[arr[pr1+prvt]] = valid[arr[t]] = valid[arr[t-(i*6)+2]] = false;
                int mn = INF;
                int res = -1;
                for(int k = 1; k <= 5; ++k) {
                    if(!valid[k]) continue;
                    if(cnt[k] < mn) {
                        mn = cnt[k];
                        res = k;
                    }
                }
                arr[++t] = res;
                cnt[res]++;
                pr1 = pr2;
                pr2++;
            }
            else if((j % i) == 0) {
                valid[arr[pr1+prvt]] = valid[arr[t]] = false;
                int mn = INF;
                int res = -1;
                for(int k = 1; k <= 5; ++k) {
                    if(!valid[k]) continue;
                    if(cnt[k] < mn) {
                        mn = cnt[k];
                        res = k;
                    }
                }
                arr[++t] = res;
                cnt[res]++;
            }
            else if(j == 1) {
                valid[arr[pr2+prvt]] = valid[arr[pr1+prvt]] = false;
                int mn = INF;
                int res = -1;
                for(int k = 1; k <= 5; ++k) {
                    if(!valid[k]) continue;
                    if(cnt[k] < mn) {
                        mn = cnt[k];
                        res = k;
                    }
                }
                arr[++t] = res;
                cnt[res]++;
                pr1 = pr2;
                pr2++;
            }
            else {
                valid[arr[pr2+prvt]] = valid[arr[pr1+prvt]] = valid[arr[t]] = false;
                int mn = INF;
                int res = -1;
                for(int k = 1; k <= 5; ++k) {
                    if(!valid[k]) continue;
                    if(cnt[k] < mn) {
                        mn = cnt[k];
                        res = k;
                    }
                }
                arr[++t] = res;
                cnt[res]++;
                pr1 = pr2;
                pr2++;
            }
        }
    }

}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    solve();

    cin>>C;
    for(int i = 1; i <= C; ++i) {
        cin>>N;
        cout<<arr[N]<<"\n";
    }
    
	return 0;
}