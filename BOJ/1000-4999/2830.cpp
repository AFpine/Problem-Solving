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
const int MAX = 1010101;

int N;
ll arr[MAX], cnt[25];
ll result = 0;

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

		int t = arr[i];
		for(int j = 0; j < 20; ++j) {
			if(t == 0) break;
			if(t % 2) cnt[j]++;
			t /= 2;
		}
	}
	
	for(int i = 1; i < N; ++i) {
		for(int j = 0; j < 20; ++j) {
			if(arr[i] % 2) {
				cnt[j]--;
				result += ((1LL<<j) * (N-i-cnt[j]));
			}
			else {
				result += ((1LL<<j) * (cnt[j]));
			}
			arr[i] /= 2;
		}
	}

	cout<<result;
	
	return 0;
}