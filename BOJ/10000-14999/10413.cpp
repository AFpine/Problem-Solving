#include <bits/stdc++.h>

// 10413 반복되는 부분 문자열

// update 220702

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+7;

int T, N;
int d;
int sa[MAX], isa[MAX], pos[MAX], temp[MAX], lcp[MAX];
string S;

bool compare(int i, int j) {
	if(pos[i] != pos[j]) return pos[i] < pos[j];	
	i += d;
	j += d;
	if(i < N && j < N) return pos[i] < pos[j];
	else return i > j;
}

void constructSA() {
	N = S.length();
	for(int i = 0; i < N; ++i) {
		sa[i] = i;
		pos[i] = S[i];
	}
	for(d = 1; d < N; d *= 2) {
		sort(sa, sa+N, compare);

		for(int i = 1; i < N; ++i) {
			temp[i] = temp[i-1] + compare(sa[i-1], sa[i]);
		}

		for(int i = 0; i < N; ++i) {
			pos[sa[i]] = temp[i];
		}

		if(temp[N-1] == N-1) {
			break;
		}
	}
}

void constructLCP() {
	for(int i = 0; i < N; ++i) {
		isa[sa[i]] = i;
	}
	for(int i = 0, k = 0; i < N; ++i) {     //i-th index에서 시작하는 suffix array에 대해
		if(isa[i] > 0) {
			for(int j = sa[isa[i]-1]; S[i+k] == S[j+k]; ++k);
			lcp[isa[i]] = (k > 0 ? k-- : 0);
		}
	}
}

void solve() {
	ll result = 0;
	int temp = 0;
	for(int i = 1; i < N; ++i) {
		if(lcp[i] > temp) {
			result += (lcp[i] - temp);
		}
		temp = lcp[i];
	}
	cout<<result<<'\n';
}

void input() {
	cin>>S;

	constructSA();
	constructLCP();
}

void init() {
	for(int i = 0; i < MAX; ++i) {
		sa[i] = 0;
		isa[i] = 0;
		lcp[i] = 0;
		temp[i] = 0;
		pos[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--) {
		init();
		input();
		solve();
	}

	return 0;
}