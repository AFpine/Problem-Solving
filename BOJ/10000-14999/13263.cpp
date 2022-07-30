#include <bits/stdc++.h>

// 13263 나무 자르기

// update 220730

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

int N;
ll dp[MAX], A[MAX], B[MAX];
pll line[MAX];

double cross(pll a, pll b) {
	return (1.0*b.second - a.second) / (a.first - b.first);
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>A[i];
	for(int i = 1; i <= N; ++i) cin>>B[i];
	dp[1] = 0;
}

void solve() {
	int top = 0;
	for(int i = 2; i <= N; ++i) {
		pll cur = {B[i-1], dp[i-1]};
		while(top > 0) {
			if(cross(line[top-1], cur) > cross(line[top-1], line[top-2])) break;
			--top;
		}
		line[top++] = cur;

		ll x = A[i];
		int pos = top-1;

		if(x < cross(line[top-1], line[top-2])) {
			int l = 0, r = top-1;
			while(l <= r) {
				int mid = (l+r)/2;
				if(x < cross(line[mid-1], line[mid])) {
					r = mid - 1;
				}
				else {
					pos = mid;
					l = mid + 1;
				}
			}
		}

		dp[i] = line[pos].first * x + line[pos].second;
	}

	cout<<dp[N];
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}