#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 1010101;

int N, M;
int arr[MAX];
int lake[MAX];
priority_queue<int, vector<int>, greater<int>> pq[MAX];
priority_queue<int, vector<int>, greater<int>> pq2;

void init() {
	for(int i = 0; i < MAX; ++i) {
		while(!pq[i].empty()) pq[i].pop();
		lake[i] = 1;
	}
	while(!pq2.empty()) pq2.pop();
}

void solve() {
	init();
	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		cin>>arr[i];
		if(arr[i] > 0) pq[arr[i]].push(i);
	}

	for(int i = 1; i <= N; ++i) {
		if(!pq[i].empty()) {
			// cout<<pq[i].top()<<" ";
			pq2.push(pq[i].top());
			pq[i].pop();
		}
	}

	vector<int> ans;
	bool invalid = false;
	for(int i = 1; i <= M; ++i) {
		if(arr[i] > 0) {
			if(lake[arr[i]] > 0) invalid = true;
			lake[arr[i]] = 1;
			if(!pq[arr[i]].empty()) {
				pq2.push(pq[arr[i]].top());
				pq[arr[i]].pop();
			}
		}
		else {
			if(!pq2.empty()) {
				ans.push_back(arr[pq2.top()]);
				lake[arr[pq2.top()]] = 0;
				pq2.pop();
			}
			else ans.push_back(0);
		}
	}
	if(invalid) {
		cout<<"NO\n";
		return;
	}
	else {
		cout<<"YES\n";
		for(auto &a : ans) cout<<a<<" ";
		cout<<'\n';
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

	int Z;
	cin>>Z;
	while(Z--) {
		solve();
	}

	return 0;
}