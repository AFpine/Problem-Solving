#include <bits/stdc++.h>

// 12906 새로운 하노이 탑

// update 220918

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
const long long MOD = 1e9+7;
const int MAX = 1005;

int cnt[3];
string ans[3];
map<string, int> maping;
queue<string> aQ, bQ, cQ;
queue<int> tQ;

bool check(string a, string b, string c) {
	auto tmp = a + "|" + b + "|" + c;
	if(maping[tmp]) return false;
	else { maping[tmp]++; return true; }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 3; ++i) {
		int n;
		string S;
		cin>>n;
		if(n == 0) {
			if(i == 0) aQ.push("");
			else if(i == 1) bQ.push("");
			else cQ.push("");
			continue;
		}
		cin>>S;
		if(i == 0) { aM[S]++; aQ.push(S); }
		else if(i == 1) { bM[S]++; bQ.push(S); }
		else { cM[S]++; cQ.push(S); }

		for(int j = 0; j < sz(S); ++j) cnt[S[j]-'A']++;
	}
	for(int i = 0; i < 3; ++i) {
		ans[i] = "";
		for(int j = 0; j < cnt[i]; ++j) ans[i].push_back((char)(i+'A'));
	}
	check(aQ.front(), bQ.front(), cQ.front());
	int result = 0;
	tQ.push(0);
	while(!aQ.empty()) {
		auto a = aQ.front();
		aQ.pop();
		auto b = bQ.front();
		bQ.pop();
		auto c = cQ.front();
		cQ.pop();
		auto t = tQ.front();
		tQ.pop();

		// cout<<a<<"|"<<b<<"|"<<c<<" "<<aM[a]<<" "<<bM[b]<<" "<<cM[c]<<'\n';

		if(a == ans[0] && b == ans[1] && c == ans[2]) { result = t; break; }

		if(sz(a) && a != ans[0]) {
			auto tmp = a.back();
			a.pop_back();

			b.push_back(tmp);
			if(check(a, b, c)) {

				aQ.push(a), bQ.push(b), cQ.push(c), tQ.push(t+1);
			}
			b.pop_back();
			c.push_back(tmp);
			if(check(a, b, c)) {
				aQ.push(a), bQ.push(b), cQ.push(c), tQ.push(t+1);
			}
			c.pop_back();
			a.push_back(tmp);
		}
		if(sz(b) && b != ans[1]) {
			auto tmp = b.back();
			b.pop_back();

			a.push_back(tmp);
			if(check(a, b, c)) {
				aQ.push(a), bQ.push(b), cQ.push(c), tQ.push(t+1);
			}
			a.pop_back();
			c.push_back(tmp);
			if(check(a, b, c)) {
				aQ.push(a), bQ.push(b), cQ.push(c), tQ.push(t+1);
			}
			c.pop_back();
			b.push_back(tmp);
		}
		if(sz(c) && c != ans[2]) {
			auto tmp = c.back();
			c.pop_back();

			b.push_back(tmp);
			if(check(a, b, c)) {
				aQ.push(a), bQ.push(b), cQ.push(c), tQ.push(t+1);
			}
			b.pop_back();
			a.push_back(tmp);
			if(check(a, b, c)) {
				aQ.push(a), bQ.push(b), cQ.push(c), tQ.push(t+1);
			}
			a.pop_back();
			c.push_back(tmp);
		}
	}

	cout<<result;
}