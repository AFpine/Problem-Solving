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

double x_1, y_1, r_1, x_2, y_2, r_2;

double dist(double x_1, double y_1, double x_2, double y_2) {
	return sqrt((x_1-x_2) * (x_1-x_2) + (y_1-y_2) * (y_1-y_2));
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(3);

	cin>>x_1>>y_1>>r_1>>x_2>>y_2>>r_2;
	
	double d = dist(x_1, y_1, x_2, y_2);
	if(d >= (r_1+r_2)) {
		cout<<"0.000";
	}
	else if(d <= abs(r_1 - r_2)) {
		cout<<min(r_1*r_1*PI, r_2*r_2*PI);
	}
	else {
		double t1 = acos((r_1*r_1 - r_2*r_2 + d*d)/(2*r_1*d));
		double t2 = acos((r_2*r_2 - r_1*r_1 + d*d)/(2*r_2*d));

		cout<<(r_1*r_1*t1) + (r_2*r_2*t2) - (r_1*r_1*sin(t1*2))/2 - (r_2*r_2*sin(t2*2))/2;
	}

	return 0;
}
