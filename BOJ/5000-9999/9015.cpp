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
const long long MOD = 1e9+9;
const int MAX = 1010101;

int N;
int result;

ll hashing(pii a) {
	return a.first * 20011LL + a.second;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;
	while(T--) {
		result = 0;
		vector<pii> arr;
		set<pii> s;
		
		cin>>N;

		for(int i = 0; i < N; ++i) {
			int x, y;
			cin>>x>>y;
			x += 10000LL;
			y += 10000LL;
			arr.push_back({x, y});
			s.insert({x, y});
		}
		sort(arr.begin(), arr.end());

		for(int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j) {
				pii v = { arr[i].first - arr[j].first , arr[i].second - arr[j].second };
				if(s.find({arr[i].first - v.second , arr[i].second + v.first}) != s.end() && s.find({arr[j].first - v.second , arr[j].second + v.first}) != s.end()) {
					result = max(result, v.first * v.first + v.second * v.second);
				}
			}
		}
		cout<<result<<"\n";
	}

	return 0;
}