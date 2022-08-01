#include <bits/stdc++.h>

// 6171 땅따먹기

// update 220801

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 50005;
const long long MOD = 1e9+7;

struct compare {
	bool operator() (const pll &a, const pll &b) {
		if(a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
};

int N;
pll WH[MAX], line[MAX];
ll dp[MAX];
deque<pll> V;

priority_queue<pll, vector<pll>, compare> pq;

double cross(pll a, pll b) {
	return (1.0*b.second - a.second) / (a.first - b.first);
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>WH[i].first>>WH[i].second;
	}
	for(int i = 1; i <= N; ++i) pq.push(WH[i]);
	// while(!pq.empty()) {
	// 	cout<<pq.top().first<<" "<<pq.top().second<<"\n";
	// 	pq.pop();
	// }
}

void solve() {
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		while(!pq.empty()) {
			if(pq.top().second <= cur.second) pq.pop();
			else break;
		}
		V.push_front(cur);
	}

	// for(auto &p : V) {
	// 	cout<<p.first<<" "<<p.second<<'\n';
	// }

	int top = 0;
	dp[0] = 0;
	for(int i = 1; i <= V.size(); ++i) {
		pll cur = {V[i-1].second, dp[i-1]};
		while(top > 0) {
			if(cross(line[top-1], line[top-2]) < cross(line[top-1], cur)) break;
			--top;
		}
		line[top++] = cur;

		ll x = V[i-1].first;
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
		dp[i] = x*line[pos].first + line[pos].second;
	}
	cout<<dp[V.size()];
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}