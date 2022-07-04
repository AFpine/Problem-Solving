#include <bits/stdc++.h>

// 10747 Censoring

// update 220704

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int, int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

string S,P;
int N,M;
int fail[MAX];
char result[MAX];
int idx;
int temp[MAX];

void getFail() {
	M = P.length();
	for(int i = 1, j = 0; i < M; ++i) {
		while(j > 0 && P[i] != P[j]) j = fail[j-1];
		if(P[i] == P[j]) fail[i] = ++j;
	}
}

void KMP() {
	N = S.length();
	for(int i = 0, j = 0; i < N; ++i) {
		while(j > 0 && S[i] != P[j]) j = fail[j-1];
		if(S[i] == P[j]) j++;
		result[idx] = S[i];
		temp[idx] = j;
		if(j == M) {
			idx -= M;
			j = temp[idx];
		}
		idx++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>S;
	cin>>P;

	getFail();

	KMP();

	for(int i = 0; i < idx; ++i) cout<<result[i];

	return 0;
}