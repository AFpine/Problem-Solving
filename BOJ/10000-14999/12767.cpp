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
const int MAX = 3030303;

int n, k;
vector<int> v;
int sel[MAX];
map<vector<int>, int> mp;
int result;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	
	for(int i = 1; i <= n; ++i) {
		v.clear();
		fill(sel, sel+MAX, 0);
		for(int j = 1; j <= k; ++j) {
			int t;
			cin>>t;
			int r = 1;
			while(true) {
				if(sel[r] == 0) {
					sel[r] = t;
					v.push_back(r);
					break;
				}
				else if(sel[r] > t) {
					r = r * 2;
				}
				else {
					r = r * 2 + 1;
				}
			}
		}
		sort(v.begin(), v.end());
		if(mp[v] == 0) result++;
		mp[v]++;
	}

	cout<<result;

	return 0;
}