#include <bits/stdc++.h>

// 4008 특공대

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
const int MAX = 1000005;
const long long MOD = 1e9+7;

ll N, A, B, C;
ll X[MAX], dp[MAX];
pll line[MAX];

// a와 b의 순서는 아무 상관 x
double cross(pll a, pll b) {
	return (1.0*b.second - a.second) / (a.first - b.first);
}

ll calculate(ll x) {
	return A*x*x + B*x + C;
}

void input() {
	cin>>N;
	cin>>A>>B>>C;
	for(int i = 1; i <= N; ++i) cin>>X[i];
	for(int i = 1; i <= N; ++i) X[i] += X[i-1];
}

void solve() {
	int top = 0;
	dp[0] = 0;
	for(int i = 1; i <= N; ++i) {
		// f(x) = Ax + B 에서 {A, B}로 linear function을 만든다
		pll cur = {((-2)*A*X[i-1]+B), (A*X[i-1]*X[i-1]-B*X[i-1]+dp[i-1])};
		while(top > 0) {
			if(cross(line[top-1], line[top-2]) < cross(line[top-1], cur)) break;
			--top;
		}
		line[top++] = cur;
		
		// 이 시점에서 (j < i)인 j에 대한 linear fuction들 중 convex hull을 이루는 함수들로 되어있다
		// 그러므로 이 안에서 이분탐색을 돌리면 (j < i)인 유효한 모든 j를 보는 것이다

		ll x = X[i];
		int pos = top-1;
		if(x < cross(line[top-1], line[top-2])) {
			int l = 0, r = top-1;
			while(l <= r) {
				int mid = (l+r)/2;
				if(x < cross(line[mid], line[mid-1])) {
					r = mid - 1;
				}
				else {
					pos = mid;
					l = mid + 1;
				}
			}
		}
		dp[i] = line[pos].first*x + line[pos].second + A*x*x + C;
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