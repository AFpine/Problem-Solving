#include <bits/stdc++.h>

// 14413 Poklon

// update 220714

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 500005;
const long long MOD = 1e9+7;

const int sq = 300;

struct Query {
	int l, r, idx;
	bool operator<(const Query &O) {
		if((l/sq) == (O.l/sq)) return r < O.r;
		return l < O.l;
	}
};
Query query[MAX];

int N, Q;
vector<int> temp;
int arr[MAX], cnt[MAX], result[MAX];

void input() {
	cin>>N>>Q;
	for(int i = 1; i <= N; ++i) {
		int x;
		cin>>x;
		temp.push_back(x);
		arr[i] = x;
	}
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for(int i = 1; i <= N; ++i) {
		arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
	}
	
	for(int i = 1; i <= Q; ++i) {
		query[i].idx = i;
		cin>>query[i].l>>query[i].r;
	}
	sort(query+1, query+1+Q);
}

void solve() {
	int cur = 0;
	int l = query[1].l, r = query[1].r;
	for(int i = l; i <= r; ++i) {
		cnt[arr[i]]++;
		if(cnt[arr[i]] == 2) cur++;
		else if(cnt[arr[i]] == 3) cur--;
	}
	result[query[1].idx] = cur;

	for(int i = 2; i <= Q; ++i) {
		while(query[i].l > l) {
			cnt[arr[l]]--;
			if(cnt[arr[l]] == 2) cur++;
			else if(cnt[arr[l]] == 1) cur--;
			l++;
		}
		while(query[i].l < l) {
			cnt[arr[--l]]++;
			if(cnt[arr[l]] == 2) cur++;
			else if(cnt[arr[l]] == 3) cur--;
		}
		while(query[i].r > r) {
			cnt[arr[++r]]++;
			if(cnt[arr[r]] == 2) cur++;
			else if(cnt[arr[r]] == 3) cur--;
		}
		while(query[i].r < r) {
			cnt[arr[r]]--;
			if(cnt[arr[r]] == 2) cur++;
			else if(cnt[arr[r]] == 1) cur--;
			r--;
		}
		result[query[i].idx] = cur;
	}

	for(int i = 1; i <= Q; ++i) cout<<result[i]<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}