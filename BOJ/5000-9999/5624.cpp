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
const int MAX = 5050;

int N, arr[MAX];
int result;
unordered_map<int, int> mp;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
	
	mp[(arr[1] + arr[1])]++;
	for(int i = 2; i <= N; ++i) {
		for(int j = 1; j < i; ++j) {
			if(mp[(arr[i] - arr[j])] > 0) {
				result++;
				break;
			}
		}
		for(int j = 1; j < i; ++j) {
			mp[(arr[i] + arr[j])]++;
		}
		mp[(arr[i] + arr[i])]++;
	}

	cout<<result;

	return 0;
}