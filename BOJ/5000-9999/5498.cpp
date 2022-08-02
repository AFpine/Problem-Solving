#include <bits/stdc++.h>

// 5498 Batch Scheduling

// update 220802

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 10005;
const long long MOD = 1e9+7;


ll N, S;
ll F[MAX], T[MAX], dp[MAX];

double cross(pll a, pll b) {
	return (double)(b.second - a.second) / (a.first - b.first);
}

void input() {
	cin>>N;
	cin>>S;
	for(int i = 1; i <= N; ++i) cin>>T[i]>>F[i];
	for(int i = 1; i <= N; ++i) {
		T[i] += T[i-1];
		F[i] += F[i-1];
	}
}

void solve() {
	deque<pll> h;
	pll line[MAX];
	for(int i = N; i >= 1; --i) {
		pll cur = {-T[i], dp[i+1] + T[i]*F[N]};
		while(sz(h) >= 2) {
			auto f = h[0];
			auto g = h[1];
			if(cross(cur, f) >= cross(g, f)) h.pop_front();
			else break;
		}
		h.push_front(cur);
		ll x = F[i-1];
		int pos = sz(h)-1;
		int l = 0, r = sz(h)-1;
		while(l <= r) {
			int mid = (l+r)/2;
			if(x > cross(h[mid], h[mid+1])) l = mid + 1;
			else {
				pos = mid;
				r = mid - 1;
			}
		}
		dp[i] = h[pos].first*x + h[pos].second + S*F[N] + T[i-1]*x - T[i-1]*F[N] - S*x;
	}
	cout<<dp[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}