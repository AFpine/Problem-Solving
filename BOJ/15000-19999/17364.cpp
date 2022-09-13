#include <bits/stdc++.h>

// 17364 대회

// update 220913

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
const int MAX = 400005;

int N, K;
int S = 0, E = MAX-1;
pii arr[MAX];
ll psum[MAX];

void cc() {
	vector<int> tmp;
	for(int i = 1; i <= N; ++i) {
		tmp.push_back(arr[i].first);
		tmp.push_back(arr[i].second);
	}
	sort(all(tmp));
	tmp.erase(unique(all(tmp)), tmp.end());

	for(int i = 1; i <= N; ++i) {
		arr[i].first = lower_bound(all(tmp), arr[i].first) - tmp.begin();
		arr[i].second = lower_bound(all(tmp), arr[i].second) - tmp.begin();
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i].first>>arr[i].second;
	}

	cc();

	sort(arr+1, arr+1+N, [](pii a, pii b) {
		if(a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	multiset<int> s;
	for(int i = 1; i <= K-1; ++i) s.insert(-1);

	int ans = 0;
	int hs = -1;
	for(int i = 1; i <= N; ++i) {
		pii cur = arr[i];

		if(cur.first <= hs) continue;
		if(s.empty()) { ans++; hs = cur.second; continue; }
		
		auto it = s.lower_bound(cur.first);
		if(it == s.begin()) {
			ans++;
			hs = cur.second;
		}
		else {
			s.erase(prev(it));
			s.insert(cur.second);
		}
	}

	cout<<ans;

	return 0;
}