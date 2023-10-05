#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 20202;

int mx = 0;
int ans[5];
int X, A, B, C, D;

void init() {
	mx = 0;
	for(int i = 0; i < 5; ++i) ans[i] = 0;
}

void f(int t, int x, int ra, int rb, int rc, int rd) {
	if(x < 0) return;
	if(t == 4 && x != 0) return;
	if(x == 0) {
		if((ra + rb + rc + rd) > mx) {
			mx = (ra + rb + rc + rd);
			ans[1] = ra;
			ans[2] = rb;
			ans[3] = rc;
			ans[4] = rd;
		}
		return;
	}

	if(t == 1) {
		int a = A;
		if(a >= x) {
			mx = x;
			ans[1] = x;
			return;
		}
		int i_a = 0;
		if((x%10) <= 4) {
			if(a < (x%10)) return;
			i_a = (x%10);
			a -= i_a;
		}
		else {
			if(a < (x%10)-5) return;
			i_a = (x%10)-5;
			a -= i_a;
		}
		int i = 0;
		while(a >= 0) {
			f(2, x-(i_a + 5*i), (i_a + 5*i), rb, rc, rd);
			i++;
			a -= 5;
		}
	}
	else if(t == 2) {
		int b = B;
		int i = 0;
		while(b >= 0) {
			f(3, x-(5*i), ra, i, rc, rd);
			i++;
			b--;
		}
	}
	else if(t == 3) {
		int	c = C;
		int d = D;
		if(rd == 1) d--;

		if(x % 10 == 0) {
			if(x <= 10*c) {
				f(4, 0, ra, rb, x/10, rd);	
			}
			else {
				x -= 10*c;
				int i = x / 50;
				int j = x % 50;
				if(j == 0) {
					if(i*2 <= d) f(4, 0, ra, rb, c, rd + i*2);
				}
				else {
					if(i*2+2 <= d) {
						j /= 10;
						if(c >= (5-j)) f(4, 0, ra, rb, c-(5-j), rd + i*2+2);
					}
				}
			}
		}
		else {
			if(d >= 1) {
				f(3, x-25, ra, rb, rc, 1);
			}
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

	cin>>X>>A>>B>>C>>D;
	
	init();
	f(1, X, 0, 0, 0, 0);
	for(int i = 1; i <= 4; ++i) cout<<ans[i]<<" ";
	cout<<"\n";
	// for(int i = 1; i <= 10; ++i) {
	// }

	return 0;
}
