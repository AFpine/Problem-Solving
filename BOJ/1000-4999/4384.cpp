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

int N;
int arr[MAX];
int total;
bool dp[105][51][22555];
int result = INF;
vector<int> res;

void f(int i, int j, int k) {
    if(i == N+1) {
        if(j == (N/2)) {
            res.push_back(k);
        }
        return;
    }
    if(j < 0) return;
    if(k > (total/2)+10) return;

    auto &ret = dp[i][j][k];
    if(ret) return;
    ret = true;

    f(i+1, j, k);
    f(i+1, j+1, k+arr[i]);
    return;
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
        cin>>arr[i];
        total += arr[i];
    }

    f(1, 0, 0);
    int mn = INF;
    for(auto &i : res) {
        if(mn > abs(i - (total - i))) {
            mn = abs(i - (total - i));
            result = i;
        }
    }

    int result2 = total - result;
    cout<<min(result, result2)<<" "<<max(result, result2);

	return 0;
}