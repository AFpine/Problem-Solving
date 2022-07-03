#include <bits/stdc++.h>

// 1093 스티커 수집

// update 220703

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 35;
const long long MOD = 1e9+7;

int N, K, mid;
//first : cost, second : value
ll start;
pll sticker[MAX];
ll result = llINF;
vector<pll> V;
map<ll, ll> M;

bool compare(pll a, pll b) {
	return a.second < b.second;
}

void recur1(int n, pll cur) {
	if(n > mid) {
		V.push_back(cur);
		return;
	}
	recur1(n+1, cur);
	recur1(n+1, {cur.first+sticker[n].first, cur.second+sticker[n].second});
}

void recur2(int n, pll cur) {
	if(n >= N) {
		if(cur.second >= K) {
			result = min(result, cur.first);
			return;
		}
		auto it = lower_bound(V.begin(), V.end(), pll(1LL,K-cur.second), compare);
		if(it == V.end()) return;
		result = min(result, (cur.first + (*it).first));
		return;
	}

	recur2(n+1, cur);
	recur2(n+1, {cur.first+sticker[n].first, cur.second+sticker[n].second});
}


void solve() {
	mid = N/2;

	recur1(0, {0,0});
	sort(V.begin(), V.end(), [] (pll a, pll b) {
		if(a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	ll temp = V.back().first;
	for(int i = V.size()-1; i >= 0; --i) {
		if(V[i].first > temp) V[i].second = -llINF;
		else temp = V[i].first;
	}

	sort(V.begin(), V.end(), [] (pll a, pll b) {
		if(a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	recur2(mid+1, {0,0});

	if(result == llINF) cout<<"-1";
	else if(result - start < 0) cout<<"0";
	else cout<<result - start;
}

void input() {
	cin>>N;
	for(int i = 0; i < N; ++i) cin>>sticker[i].first;
	for(int i = 0; i < N; ++i) cin>>sticker[i].second;
	cin>>K;
	int t;
	cin>>t;
	while(t--) {
		int temp;
		cin>>temp;
		start += sticker[temp].first;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}