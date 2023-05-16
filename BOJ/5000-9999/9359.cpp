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
const int MAX = 101010;

ll A, B, N, result;
vector<ll> prime;
// bool isPrime[MAX + 1];
// vector<ll> prime(1, 2);
// void getPrime() {
// 	fill(isPrime + 2, isPrime + MAX + 1, 1);
// 	for (ll i = 4; i <= MAX; i += 2)
// 		isPrime[i] = 0;
// 	for (ll i = 3; i <= MAX; i += 2) {
// 		if (!isPrime[i]) continue;
// 		prime.push_back(i);
// 		for (ll j = i * i; j <= MAX; j += i * 2)
// 			isPrime[j] = 0;
// 	}
// }

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// getPrime();

	int T;
	cin>>T;
	for(int t = 1; t <= T; ++t) {
		prime.clear();
		result = 0;

		cin>>A>>B>>N;
		
		auto tmp = N;
		for(ll i = 2; i*i <= N; ++i) {
			if(tmp % i == 0) {
				prime.push_back(i);
				while(tmp % i == 0) tmp /= i;
			}
		}
		if(tmp != 1) prime.push_back(tmp);

		ll k = prime.size();
		for(ll i = 1; i < (1LL << k); ++i) {
			ll cnt = 0;
			ll sum = 1;
			for(ll j = 0; j < k; ++j) {
				if(i & (1LL << j)) {
					cnt++;	// cnt 개의 소인수로 이루어진 sum으로 나눌 것
					sum *= prime[j];
				}
			}
			ll aa = (A-1LL)/sum; // aa : [1, A-1] 까지 sum의 배수의 개수
			ll bb = B/sum;	// bb : [1, B] 까지 sum의 배수의 개수
			if(cnt & 1) result += bb-aa;
			else result -= bb-aa;
		}
		cout<<"Case #"<<t<<": "<<B-A+1LL-result<<'\n';
	}

	return 0;
}