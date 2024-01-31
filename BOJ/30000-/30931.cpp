#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 222;

string S;
string dp[MAX][MAX];

string f(int s, int e) {
	auto &ret = dp[s][e];
	if(s == e) {
		ret = S[s];
		return ret;
	}
	if(ret != "") return ret;

	int len = (e - s + 1);
	
	ret = S.substr(s, len);
	for(int k = len; k >= 1; --k) {
		if(len % k) continue;
		int cnt = len / k;
		if(cnt >= 10) break;

		bool invalid = false;
		for(int i = 0; i < k; ++i) {
			if(invalid) break;
			for(int j = 1; j < cnt; ++j) {
				if(S[s + i] != S[s + i + (j*k)]) {
					invalid = true;
					break;
				}
			}
		}
		if(invalid) continue;

		string tmp = "";
		tmp += ('0' + cnt);
		tmp += '(';
		tmp += f(s, s+k-1);
		tmp += ')';

		if(tmp.length() < ret.length()) {
			ret = tmp;
		}
	}

	for(int k = s; k < e; ++k) {
		if((f(s, k).length() + f(k+1, e).length()) < ret.length()) {
			ret = f(s, k) + f(k+1, e);
		}
	}
	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) dp[i][j] = "";
	}

	cin>>S;

	cout<<f(0, S.length()-1);

	return 0;
}