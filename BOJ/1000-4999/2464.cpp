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
const int MAX = 100;

ll A;
vector<int> big, small;
int cnt;
ll bigres, smallres;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>A;

	while(A) {
		big.push_back(A % 2);
		if(A % 2) cnt++;
		A /= 2;
	}

	reverse(big.begin(), big.end());
	small = big;

	int n = big.size();
	int c = 0;
	int flag = 0;
	for(int i = n-1; i > 0; --i) {
		if(big[i] == 1 && big[i-1] == 0) {
			swap(big[i], big[i-1]);
			flag++;
			for(int j = n-1; j >= i+1; --j) {
				if(c > 0) {
					big[j] = 1;
					c--;
				}
				else big[j] = 0;
			}
			break;
		}
		else if(big[i] == 1) c++;
	}
	if(flag == 0) {
		c = cnt-1;
		big.resize(n+1);
		big[0] = 1;
		for(int j = n; j > 0; --j) {
			if(c > 0) {
				big[j] = 1;
				c--;
			}
			else big[j] = 0;
		}
	}

	c = 0;
	flag = 0;
	for(int i = n-1; i > 0; --i) {
		if(small[i] == 0 && small[i-1] == 1) {
			swap(small[i], small[i-1]);
			flag++;
			for(int j = i+1; j < n; ++j) {
				if(c > 0) {
					small[j] = 1;
					c--;
				}
				else small[j] = 0;
			}
			break;
		}
		else if(small[i] == 1) c++;
	}
	if(flag == 0) {
		for(int i = 0; i < n; ++i) small[i] = 0;
	}

	n = big.size();
	for(int i = 0; i < big.size(); ++i) {
		if(big[n-i-1] == 1) {
			bigres += (1LL << i);
		}
	}
	n = small.size();
	for(int i = 0; i < small.size(); ++i) {
		if(small[n-i-1] == 1) {
			smallres += (1LL << i);
		}
	}

	cout<<smallres<<" "<<bigres;

	return 0;
}