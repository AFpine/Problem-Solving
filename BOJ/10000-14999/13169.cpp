#include <bits/stdc++.h>

// 13169 Xor of Sums

// update 220705

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 35;
const long long MOD = 1e9+7;

int N, mid;
ll arr[MAX];
ll result = 0;
vector<ll> V[40];

void recur1(int n, ll cur) {
	if(n > mid) {
		for(int i = 0; i <= 35; ++i) {
			//부분 수열의 합을 i번째 비트까지 저장해놓은 배열
			V[i].push_back(cur & ((1LL<<(i+1))-1));
		}
		return;
	}

	recur1(n+1, cur);
	recur1(n+1, cur+arr[n]);
}

void recur2(int n, ll cur) {
	if(n > N) {
		for(int i = 0; i <= 35; ++i) {
			//temp : i-1번째 비트까지의 cur값
			ll temp = cur & ((1LL<<i)-1);

			//(1LL<<i)-1-temp 보다 큰 값들은 temp와 합쳐졌을 때, i번째 bit에 영향을 준다
			//(1LL<i)-1 = i-1번째 까지 1로 채워진 수 , 이 수 보다 커진다면, i번째 bit에 영향을 준다 (0에서 1 or 1에서 0)
			auto it1 = upper_bound(V[i].begin(), V[i].end(), (1LL<<i)-1-temp) - V[i].begin();
			//(1LL<<(i+1)-1) 보다 큰 수는 V[i]에서 순서가 달라졌을 것이다 (it1에서 이미 고려되었을 것이다)
			auto it2 = upper_bound(V[i].begin(), V[i].end(), (1LL<<(i+1))-1-temp) - V[i].begin();

			//조건을 만족하는 값이 홀수개면, i번째 비트를 반전(bitwise XOR)
			if((it2-it1) % 2) result ^= (1LL<<i);
		}
		return;
	}

	recur2(n+1, cur);
	recur2(n+1, cur+arr[n]);
}

void solve() {
	if(N == 1) {
		cout<<arr[1];
		return;
	}

	mid = N/2;

	recur1(1, 0);

	for(int i = 0; i <= 35; ++i) sort(V[i].begin(), V[i].end());

	recur2(mid+1, 0);

	cout<<result;
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}