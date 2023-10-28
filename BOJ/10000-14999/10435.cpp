#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
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
const long long MOD = 998244353;
const int MAX = 2020;

int P, N, idx;
int arr[MAX][MAX];

void solve() {
	for(int i = 1; i <= 2000; ++i) {
		arr[i][1] += 1;
		for(int j = 1; j <= 2000; ++j) {
			if(arr[i][j] > j) {
				arr[i][j] -= j+1;
				arr[i][j+1] += j+1;
			}
			arr[i+1][j] = arr[i][j];
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

	cin>>P;
	while(P--) {
		cin>>idx>>N;
		vector<int> ans;
		for(int i = 1; i <= 2000; ++i) ans.push_back(arr[N][i]);

		int end = ans.size()-1;
		for(int i = end; i >= 0; --i) {
			if(ans[i] > 0) {
				end = i;
				break;
			}
		}
		cout<<idx<<" "<<end+1<<" ";
		for(int i = 0; i <= end; ++i) {
			if(i % 10 == 0) cout<<"\n";
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
