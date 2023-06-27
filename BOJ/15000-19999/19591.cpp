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
const int MAX = 1010101;

string S;
deque<ll> num;
deque<char> op;

int precedence(char c) {
	if(c == '*' || c == '/') return 1;
	else return 0;
}

ll calculation(ll l, ll r, char c) {
	if(c == '+') return l + r;
	else if(c == '-') return l - r;
	else if(c == '*') return l * r;
	else return l / r;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>S;

	ll a = 0;
	for(int i = 0; i < S.length(); ++i) {
		if(S[i] == '*' || S[i] == '/' || S[i] == '+' || S[i] == '-') {
			num.push_back(a);
			op.push_back(S[i]);
			a = 0;
		}
		else {
			a *= 10LL;
			a += (S[i] - '0');
		}
	}
	num.push_back(a);

	if(S[0] == '-') {
		num.pop_front();
		auto i = num.front();
		num.pop_front();
		num.push_front(-i);
		op.pop_front();
	}

	while(num.size() > 1) {
		ll n1, n2, n3, n4;
		char o1, o2;

		n1 = num.front();
		num.pop_front();
		n2 = num.front();
		num.push_front(n1);

		n4 = num.back();
		num.pop_back();
		n3 = num.back();
		num.push_back(n4);

		o1 = op.front();
		o2 = op.back();

		auto res1 = calculation(n1, n2, o1);
		auto res2 = calculation(n3, n4, o2);

		if(precedence(o1) == precedence(o2)) {
			if(res1 == res2 || res1 > res2) {
				num.pop_front();
				num.pop_front();
				num.push_front(res1);
				op.pop_front();
			}
			else
			{
				num.pop_back();
				num.pop_back();
				num.push_back(res2);
				op.pop_back();
			}
		}
		else if(precedence(o1) > precedence(o2)) {
			num.pop_front();
			num.pop_front();
			num.push_front(res1);
			op.pop_front();
		}
		else {
			num.pop_back();
			num.pop_back();
			num.push_back(res2);
			op.pop_back();
		}
	}

	cout<<num.front();

	return 0;
}