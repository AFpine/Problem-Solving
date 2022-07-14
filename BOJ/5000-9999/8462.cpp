#include <bits/stdc++.h>

// 8426 배열의 힘

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
const int MAX = 100005;
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
int arr[MAX], check[MAX*10];
ll result[MAX];

void input() {
	cin>>N>>Q;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
	}
	
	for(int i = 1; i <= Q; ++i) {
		query[i].idx = i;
		cin>>query[i].l>>query[i].r;
	}
	sort(query+1, query+1+Q);
}

void solve() {
	ll sum = 0;
	int l = query[1].l, r = query[1].r;
	for(int i = l; i <= r; ++i) {
		check[arr[i]]++;
		if(check[arr[i]] == 1) {
			sum += 1LL*arr[i];
		}
		else {
			sum -= 1LL*arr[i]*(check[arr[i]]-1)*(check[arr[i]]-1);
			sum += 1LL*arr[i]*(check[arr[i]])*(check[arr[i]]);
		}
	}
	result[query[1].idx] = sum;

	for(int i = 2; i <= Q; ++i) {
		while(query[i].l > l) {
			check[arr[l]]--;
			if(check[arr[l]] == 0) {
				sum -= arr[l];
			}
			else {
				sum -= 1LL*arr[l]*(check[arr[l]]+1)*(check[arr[l]]+1);
				sum += 1LL*arr[l]*(check[arr[l]])*(check[arr[l]]);
			}
			l++;
		}
		while(query[i].l < l) {
			check[arr[--l]]++;
			if(check[arr[l]] == 1) {
				sum += arr[l];
			}
			else {
				sum -= 1LL*arr[l]*(check[arr[l]]-1)*(check[arr[l]]-1);
				sum += 1LL*arr[l]*(check[arr[l]])*(check[arr[l]]);
			}
		}
		while(query[i].r > r) {
			check[arr[++r]]++;
			if(check[arr[r]] == 1) {
				sum += arr[r];
			}
			else {
				sum -= 1LL*arr[r]*(check[arr[r]]-1)*(check[arr[r]]-1);
				sum += 1LL*arr[r]*(check[arr[r]])*(check[arr[r]]);
			}
		}
		while(query[i].r < r) {
			check[arr[r]]--;
			if(check[arr[r]] == 0) {
				sum -= arr[r];
			}
			else {
				sum -= 1LL*arr[r]*(check[arr[r]]+1)*(check[arr[r]]+1);
				sum += 1LL*arr[r]*(check[arr[r]])*(check[arr[r]]);
			}
			r--;
		}
		result[query[i].idx] = sum;
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