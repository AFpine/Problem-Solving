#include <bits/stdc++.h>
 
// 20149 선분 교차 3
 
// update 220722

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1005;

pair<pdd, pdd> l1, l2;

pdd bigpoint(pdd a, pdd b) {
	if(a.first == b.first) {
		if(a.second < b.second) return b;
		else return a;
	}
	else if(a.first < b.first) return b;
	else return a;
}
pdd smallpoint(pdd a, pdd b) {
	if(a.first == b.first) {
		if(a.second < b.second) return a;
		else return b;
	}
	else if(a.first < b.first) return a;
	else return b;
}

long double ccw(pdd o, pdd a, pdd b) {
	return (a.first - o.first) * (b.second - o.second) - (b.first - o.first) * (a.second - o.second);
}

void input() {
	cin>>l1.first.first>>l1.first.second>>l1.second.first>>l1.second.second;
	cin>>l2.first.first>>l2.first.second>>l2.second.first>>l2.second.second;
}

void solve() {
	long double c11 = ccw(l1.first, l1.second, l2.first), c12 = ccw(l1.first, l1.second, l2.second), c21 = ccw(l2.first, l2.second, l1.first), c22 = ccw(l2.first, l2.second, l1.second);

	if(c11*c12 < 0 && c21*c22 < 0) {// cross
		cout<<"1"<<'\n';
		cout<<( ( (((l1.first.first*l1.second.second)-(l1.first.second*l1.second.first))*(l2.first.first-l2.second.first)) - ((l1.first.first-l1.second.first)*((l2.first.first*l2.second.second)-(l2.first.second*l2.second.first))) ) / (((l1.first.first-l1.second.first)*(l2.first.second-l2.second.second)) - ((l1.first.second-l1.second.second)*(l2.first.first-l2.second.first))) )<<" ";
		cout<<( ( (((l1.first.first*l1.second.second)-(l1.first.second*l1.second.first))*(l2.first.second-l2.second.second)) - ((l1.first.second-l1.second.second)*((l2.first.first*l2.second.second)-(l2.first.second*l2.second.first))) ) / (((l1.first.first-l1.second.first)*(l2.first.second-l2.second.second)) - ((l1.first.second-l1.second.second)*(l2.first.first-l2.second.first))) );
	}
	else if(c11*c12 == 0 && c21*c22 == 0) {
		if(c11 == 0 && c12 == 0 && c21 == 0 && c22 == 0) {	// on one line
			auto p1 = bigpoint(l1.first, l1.second), p2 = bigpoint(l2.first, l2.second);
			if(p1 >= p2) {
				auto sp1 = smallpoint(l1.first, l1.second);
				if(sp1 == p2) {
					cout<<"1"<<'\n'<<p2.first<<" "<<p2.second;
					return;
				}
				else if(smallpoint(sp1, p2) == sp1) {
					cout<<"1";
					return;
				}
				else {
					cout<<"0";
					return;
				}
			}
			else {
				auto sp2 = smallpoint(l2.first, l2.second);
				if(sp2 == p1) {
					cout<<"1"<<'\n'<<p1.first<<" "<<p1.second;
					return;
				}
				else if(smallpoint(sp2, p1) == sp2) {
					cout<<"1";
					return;
				}
				else {
					cout<<"0";
					return;
				}
			}
		}
		else {	//수선의 발
			if(l1.first == l2.first) {
				cout<<"1"<<'\n'<<l1.first.first<<" "<<l1.first.second;
				return;
			}
			else if(l1.first == l2.second) {
				cout<<"1"<<'\n'<<l1.first.first<<" "<<l1.first.second;
				return;
			}
			else if(l1.second == l2.first) {
				cout<<"1"<<'\n'<<l1.second.first<<" "<<l1.second.second;
				return;
			}
			else {
				cout<<"1"<<'\n'<<l1.second.first<<" "<<l1.second.second;
				return;
			}
		}
	}
	else if((c11*c12 < 0 && c21*c22 == 0) || (c11*c12 == 0 && c21*c22 < 0)) {	//수선의 발을 내린 형태
		if(c11*c12 < 0) {	// 교차점은 l1 위의 점이다
			if(ccw(l2.first, l1.first, l2.second) == 0) {
				cout<<"1"<<'\n'<<l1.first.first<<" "<<l1.first.second;
				return;
			}
			else {
				cout<<"1"<<'\n'<<l1.second.first<<" "<<l1.second.second;
				return;
			}
		}
		else {	//교차점은 l2 위의 점이다
			if(ccw(l1.first, l2.first, l1.second) == 0) {
				cout<<"1"<<'\n'<<l2.first.first<<" "<<l2.first.second;
				return;
			}
			else {
				cout<<"1"<<'\n'<<l2.second.first<<" "<<l2.second.second;
				return;
			}
		}
	}
	else if((c11*c12 < 0 && c21*c22 > 0) || (c11*c12 > 0 && c21*c22 < 0)) {
		cout<<"0";
	}
	else if(c11*c12 > 0 && c21*c22 > 0) {
		cout<<"0";
	}
	else {
		cout<<"0";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed;
	cout.precision(20);

	input();
	solve();
 
	return 0;
}