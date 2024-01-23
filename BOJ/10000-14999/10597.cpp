#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 100;

bool used[MAX];
int mx = 0;
string S;
stack<int> st;
vector<int> ans;
bool flag = false;

void f(int idx) {
	if(flag) return;

	if(idx == S.length()) {
		while(!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		for(int i = mx-1; i >= 0; --i) st.push(ans[i]); 
		flag = true;
		return;
	}

	int d1 = S[idx] - '0';
	if(d1 >= 1 && d1 <= mx && used[d1] == false) {
		used[d1] = true;
		st.push(d1);
		f(idx+1);
		used[d1] = false;
		st.pop();
	}

	int d2 = 0;
	if(idx <= S.length() - 2) {
		d2 = (S[idx] - '0') * 10;
		d2 += S[idx+1] - '0';

		if(d2 >= 10 && d2 <= mx && used[d2] == false) {
			used[d2] = true;
			st.push(d2);
			f(idx+2);
			used[d2] = false;
			st.pop();
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>S;
	if(S.length() <= 9) {
		mx = S.length();
	}
	else {
		mx = (S.length() - 9) / 2 + 9;
	}

	f(0);
	
	for(int i = mx-1; i >= 0; --i) cout<<ans[i]<<" ";

	return 0;
}