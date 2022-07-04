#include <bits/stdc++.h>

// 

// update 220704

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 40;
const long long MOD = 1e9+7;

int N, mid;
pll result = {llINF, 0};
ll arr1[MAX], arr2[MAX];
set<pll> S[20];

void recur1(int n, int cnt, ll bits, ll cur1, ll cur2) {
	if(n > mid) {
		S[cnt].insert({cur1-cur2, bits});
		return;
	}
	recur1(n+1, cnt, bits*2, cur1+arr1[n], cur2);
	recur1(n+1, cnt+1, bits*2+1, cur1, cur2+arr2[n]);
}

void recur2(int n, int cnt, ll bits, ll cur1, ll cur2) {
	if(n > N) {
		auto it = S[mid-cnt].lower_bound(pll(cur2-cur1, -llINF));

		if(it != S[mid-cnt].end()) {
			result = min(result, pll(abs((*it).first+cur1-cur2), ((*it).second)*(1LL<<(mid))+bits));
		}
		if(it != S[mid-cnt].begin()) {	//직전 iterator의 값도 비교해 볼 것
			it--;
			it = S[mid-cnt].lower_bound(pll((*it).first, -llINF));
			result = min(result, pll(abs((*it).first+cur1-cur2), ((*it).second)*(1LL<<(mid))+bits));
		}
		return;
	}

	recur2(n+1, cnt, bits*2, cur1+arr1[n], cur2);
	recur2(n+1, cnt+1, bits*2+1, cur1, cur2+arr2[n]);
}


void solve() {
	recur1(1, 0, 0LL, 0, 0);
	recur2(mid+1, 0, 0LL, 0, 0);
	for(int i = N-1; i >= 0; --i) {
		if(result.second & (1LL<<i)) cout<<"2 ";
		else cout<<"1 ";
	}
}

void input() {
	cin>>N;
	mid = N/2;
	for(int i = 1; i <= N; ++i) cin>>arr1[i];
	for(int i = 1; i <= N; ++i) cin>>arr2[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}