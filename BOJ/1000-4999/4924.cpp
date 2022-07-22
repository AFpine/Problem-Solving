#include <bits/stdc++.h>
 
// 4924 정수론 싫어

// update 220722

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1000000;

bool isPrime[MAX+5];
ll p[MAX+5];
ll psum[MAX+5];

void makePrime() {
	fill(isPrime, isPrime+MAX, true);
	for(int i = 2; i <= MAX; ++i) {
		if(isPrime[i]) {
			p[i] = -1;
			for(int j = 2; i*j <= MAX; ++j) {
				isPrime[i*j] = false;
			}
		}
	}
	p[1] = 0;
}

void solve(int u, int v, int t) {
	ll result = -INF;
	ll cur = -INF;
	for(int i = u; i <= v; ++i) {
		if(cur + p[i] - 1 < p[i] - 1) {
			cur = p[i] - 1;
		}
		else {
			cur += p[i] - 1;
		}
		result = max(result, cur);
	}	
	cout<<t<<". "<<result<<'\n';
}

void input() {
	makePrime();
	for(int i = 4; i <= MAX; ++i) {
		if(isPrime[i]) continue;
		for(int j = 2; j <= i; ++j) {
			if(i % j == 0) {
				if(isPrime[j]) p[i]++;
				else p[i] += p[j];
				if(isPrime[i/j]) p[i]++;
				else p[i] += p[i/j];
				break;
			}
		}
	}

	int t = 0;
	while(true) {
		int u, v;
		cin>>u>>v;
		if(u == -1 && v == -1) break;
		solve(u, v, ++t);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	input();
	// solve();
 
	return 0;
}