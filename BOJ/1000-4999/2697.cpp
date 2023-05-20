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
const long long MOD = 1e9+7;
const int MAX = 5050;

int P;
string S;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>P;
	while(P--) {
		cin>>S;

		int idx = -1;
		for(int i = sz(S)-2; i >= 0; --i) {
			if((S[i] - '0') < (S[i+1] - '0')) {
				idx = i;
				break;
			}
		}

		if(idx == -1) {
			cout<<"BIGGEST\n";
			continue;
		}

		auto a = S[idx] - '0';
		auto min = 10;
		int swapIdx = -1;
		for(int i = idx+1; i < sz(S); ++i) {
			if((S[i]-'0') > a && (S[i]-'0') < min) {
				min = S[i]-'0';
				swapIdx = i;
			}
		}
		swap(S[idx], S[swapIdx]);
		sort(S.begin()+idx+1, S.end());

		cout<<S<<'\n';
	}

	return 0;
}