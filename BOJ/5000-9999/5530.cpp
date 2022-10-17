#include <bits/stdc++.h>

// 5530 JOIOI 탑

// 221015

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
const int MAX = 202020;

string S;
int N;
vector<int> v;

bool check(int x) {
	int fail = v[sz(v) - x];
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < N; ++i) {
		if(S[i] == 'J') a++;
		else if(S[i] == 'I' && i < fail) a++;
		else if(S[i] == 'O' && a > 0) { a--; b++; }
		else if(S[i] == 'I' && b > 0 && i >= fail) { b--; c++; }
	}
	return x == c;
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
	int maxI = 0;
	for(int i = 0; i < N; ++i) {
		if(S[i] == 'I') v.push_back(i);
	}

	int ans = 0;
	int l = 1, r = sz(v);
	while(l <= r) {
		int mid = (l+r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;		
		}
		else {
			r = mid - 1;
		}
	}
	cout<<ans;
	
	return 0;
}