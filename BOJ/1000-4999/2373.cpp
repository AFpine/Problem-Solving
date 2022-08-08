#include <bits/stdc++.h>

// 2373 Fibonacci Game

// update 220808

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
const long long MOD = 1000000007;
const int MAX = 1000005;

int N;
bool isFibo[MAX];

void fib() {
	int f1 = 1, f2 = 1;
	while(f1 < MAX) {
		isFibo[f1] = true;
		int temp = f1 + f2;
		f2 = f1;
		f1 = temp;
	}
}

void input() {
	cin>>N;
	fib();
}

void solve() {
	if(isFibo[N]) {
		cout<<"-1";
		return;
	}
	int result = -1;
	while(true) {
		for(int i = 1; i < N; ++i) {
			if(isFibo[N-i]) {
				result = i;
				break;
			}
		}
		if(isFibo[result]) break;
		else N = result;
	}
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}