#include <bits/stdc++.h>

// 9735 삼차 방정식 풀기

// update 220711

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 7600;
const long long MOD = 2019201997;

int N;
ld A, B, C, D;
set<ld> S;

ld Discriminant(ld a, ld b, ld c) {
	return (b*b - 4*a*c);
}

void solve() {
	ld x;
	for(ld i = -2000000; i <= 2000000; ++i) {
		if((A*(i*i*i) + B*(i*i) + C*i + D) == 0) {
			x = i;
			break;
		}
	}

	S.insert((double)x);

	D = A*(x*x) + B*x + C;
	C = A*x + B;
	B = A;

	ld d = Discriminant(B, C, D);

	if(d < 0) {
		cout<<x<<'\n';
		return;
	}

	S.insert((-C + sqrt(d)) / (2.0*B));
	S.insert((-C - sqrt(d)) / (2.0*B));

	for(auto &s : S) {
		cout<<s<<" ";
	}
	cout<<'\n';
}

void input() {
	S.clear();
	cin>>A>>B>>C>>D;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	while(N--) {
		input();
		solve();
	}
	

	return 0;
}