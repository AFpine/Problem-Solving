#include <bits/stdc++.h>
 
// 1891 사분면

// update 220804

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int MAX = 55;

int d;
char D[MAX];
char result[MAX];
ll x, y, maxN, curN;

void input() {
	cin>>d;
	for(int i = 0; i < d; ++i) {
		cin>>D[i];
	}
	cin>>x>>y;
	curN = maxN = pow(2, d);
}

void solve() {
	pll pos = {0, 0};
	for(int i = 0; i < d; ++i) {
		auto k = D[i] - '0';
		curN /= 2;
		if(k == 1) {
			pos = {pos.first, pos.second + curN};
		}
		else if(k == 3) {
			pos = {pos.first + curN, pos.second};
		}
		else if(k == 4) {
			pos = {pos.first + curN, pos.second + curN};
		}
	}
	pos = {pos.first - y, pos.second + x};

	// cout<<pos.first<<" "<<pos.second<<'\n';

	if(pos.first < 0 || pos.first >= maxN || pos.second < 0 || pos.second >= maxN) {
		cout<<"-1";
		return;
	}

	pll temp = {0, 0};
	curN = maxN;
	for(int i = 0; i < d; ++i) {
		curN /= 2;
		if(temp.first + curN <= pos.first) {
			temp.first += curN;
			if(temp.second + curN <= pos.second) {
				result[i] = '4';
				temp.second += curN;
			}
			else {
				result[i] = '3';
			}
		}
		else {
			if(temp.second + curN <= pos.second) {
				result[i] = '1';
				temp.second += curN;
			}
			else {
				result[i] = '2';
			}
		}
	}
	for(int i = 0; i < d; ++i) {
		cout<<result[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}