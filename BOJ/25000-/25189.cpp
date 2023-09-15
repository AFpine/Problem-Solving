#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
const long long MOD = 998244353;
const int MAX = 101010;

int W;
int mx_depth, idx;
int parent[MAX], w[MAX];
vector<int> depth[MAX];
vector<int> child[MAX];
int ans = 0;

int input(int d) {
	int cur = ++idx;
	int M, N;

	cin>>M>>N;
	w[cur] = M;
	depth[d].push_back(cur);
	mx_depth = max(mx_depth, d);

	for(int i = 1; i <= N; ++i) {
		child[cur].push_back(input(d+1));
	}
	return cur;
}

void solve(int idx) {
	int child_sum = 0;
	priority_queue<int> pq;
	for(auto &c : child[idx]) {
		child_sum += w[c];
		pq.push(w[c]);
	}

	while(!pq.empty() && child_sum > W) {
		auto cur = pq.top();
		pq.pop();
		ans++;
		child_sum -= cur;
	}

	w[idx] += child_sum;
	if(w[idx] > W) {
		if(w[idx] % W == 0) {
			ans += (w[idx]/W - 1);
			w[idx] = W;
		}
		else {
			ans += w[idx]/W;
			w[idx] %= W;
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>W;
	input(0);

	for(int d = mx_depth; d >= 0; --d) {
		for(auto &i : depth[d]) {
			solve(i);
		}
	}
	
	cout<<ans+1;
	
	return 0;
}
