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
const int MAX = 2020;

int N;
int arr[MAX];
int lis[MAX], lds[MAX];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
	
	for(int i = N; i >= 1; --i) {
		lis[i] = lds[i] = 1;
		for(int j = N; j > i; --j) {
			if(arr[j] > arr[i]) lis[i] = max(lis[i], lis[j] + 1);
			if(arr[j] < arr[i]) lds[i] = max(lds[i], lds[j] + 1);
		}
	}

	int result = 0;
	for(int i = 1; i <= N; ++i) result = max(result, lis[i] + lds[i] - 1);

	cout<<result;

	return 0;
}