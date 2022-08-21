#include <bits/stdc++.h>
 
// 20302 민트 초코

// update 220821

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 9999991;
const int MAX = 100005;

int N, cnt[MAX+1];
bool isPrime[MAX+1];
vector<int> prime(1, 2), nume, deno;

void getPrime() {
	fill(isPrime + 2, isPrime + MAX + 1, 1);

	for (ll i = 4; i <= MAX; i += 2)
		isPrime[i] = 0;
	for (ll i = 3; i <= MAX; i++) {
		if (isPrime[i]) prime.push_back(i);
		for (ll j = i * i; j <= MAX; j += i * 2)
			isPrime[j] = 0;
	}
}

void factorize(int n, int k) {
	while(true) {
		if(n == 1) return;
		if(isPrime[n]) {
			cnt[n] += k;
			break;
		}
		for(int i = 0; i < sz(prime); ++i) {
			if(n % prime[i] == 0) {
				cnt[prime[i]] += k;
				n /= prime[i];
				break;
			}
		}
	}
}

void input() {
	cin>>N;
	int i = 1, d;
	char c;

	cin>>d;
	nume.push_back(abs(d));
	while(true) {
		if(i >= N) break;
		cin>>c;
		cin>>d;
		if(c == '*') nume.push_back(abs(d));
		else deno.push_back(abs(d));
		i++;
	}
	getPrime();
}

void solve() {
	for(auto &i : nume) {
		if(i == 0) {
			cout<<"mint chocolate";
			return;
		}
		factorize(i, 1);
	}
	for(auto &i : deno) {
		factorize(i, -1);
	}
	
	bool incorrect = false;
	for(int i = 0; i < MAX; ++i) {
		if(cnt[i] < 0) incorrect = true;
	}
	if(incorrect) cout<<"toothpaste";
	else cout<<"mint chocolate";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}