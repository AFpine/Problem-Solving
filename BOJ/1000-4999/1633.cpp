#include <bits/stdc++.h>
 
// 1633 최고의 팀 만들기

// update 220721
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const long long MOD = 1e9+7;

int cnt;
bool selected[MAX];
vector<pair<int, pii>> arr;
vector<pii> dparr;	
ll dp[65][20][20];

ll f(int n, int w, int b) {
	ll &ret = dp[n][w][b];

	if(n >= dparr.size()) return 0;
	if(ret != -1) return ret;

	ret = 0;
	if(w < 15) {
		ret = max(ret, dparr[n].first + f(n+1, w+1, b));
	}
	if(b < 15) {
		ret = max(ret, dparr[n].second + f(n+1, w, b+1));
	}
	ret = max(ret, f(n+1, w, b));

	return ret;
}

void input() {
	int w, b;
	while(cin>>w>>b) {
		// cin>>w>>b;
		arr.push_back({cnt++, {w, b}});
	}

	memset(dp, -1, sizeof(dp));
	fill(selected, selected+MAX, false);
}

void solve() {
	vector<pair<int, pii>> temp = arr;
	sort(temp.begin(), temp.end(), [] (pair<int, pii> a, pair<int, pii> b) {
		return a.second.first > b.second.first;
	});
	for(int i = 0; i < 30; ++i) {
		selected[temp[i].first] = true;
	}

	sort(temp.begin(), temp.end(), [] (pair<int, pii> a, pair<int, pii> b) {
		return a.second.second > b.second.second;
	});
	for(int i = 0; i < 30; ++i) {
		selected[temp[i].first] = true;
	}

	for(int i = 0; i < cnt; ++i) {
		if(selected[i]) dparr.push_back({arr[i].second.first, arr[i].second.second});
	} 

	ll result = f(0, 0, 0);

	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}