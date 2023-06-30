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
const long long MOD = 1e9+9;
const int MAX = 15;

int N;
string S;
vector<char> op;
vector<int> val;
bool selo[MAX], selv[MAX], paren[MAX];
int result = -INF;

int precedence(char c) {
	if(c == '*') return 2;
	else return 1;
}

int calculation(int a, int b, char c) {
	if(c == '+') return a + b;
	else if(c == '-') return a - b;
	else return a * b;
}

void backtracking(int cnt) {
	if(cnt == N/2) {
		result = max(result, val[0]);
		return;
	}

	vector<int> o, v;
	int opidx = -1, oopidx = -1, idx = 0, prec = 0;
	for(int i = 0; i < sz(op); ++i) {
		if(selo[i]) continue;
		if(precedence(op[i]) > prec) {
			prec = precedence(op[i]);
			opidx = i;
			oopidx = idx;
		}
		idx++;
		o.push_back(i);
	}

	int n1 = 0, n2 = 0;
	idx = 0;
	for(int i = 0; i < sz(val); ++i) {
		if(selv[i]) continue;
		if(idx == oopidx) n1 = i;
		if(idx == oopidx+1) n2 = i;
		idx++;
		v.push_back(i);
	}

	selo[opidx] = selv[n2] = true;
	int tmp = val[n1];
	val[n1] = calculation(tmp, val[n2], op[opidx]);

	backtracking(cnt+1);

	selo[opidx] = selv[n2] = false;
	val[n1] = tmp;

	for(int i = 0; i < sz(v) - 1; ++i) {
		if(o[i] == opidx) continue;
		selo[o[i]] = selv[v[i+1]] = true;
		int tmp = val[v[i]];
		val[v[i]] = calculation(tmp, val[v[i+1]], op[o[i]]);

		backtracking(cnt+1);

		selo[o[i]] = selv[v[i+1]] = false;
		val[v[i]] = tmp;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>S;

	for(int i = 0; i < sz(S); ++i) {
		if(i % 2) {
			op.push_back(S[i]);
		}
		else {
			val.push_back(S[i] - '0');
		}
	}

	backtracking(0);
	cout<<result;
	
	return 0;
}
