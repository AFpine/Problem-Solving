#include <bits/stdc++.h>

// 12921 제한된 메모리

// update 220716

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const long long MOD = 1e9+7;

ll N, x0, a, b;
int Q, q[MAX], mid[MAX], psum[MAX];
pii lr[MAX];

void input() {
	cin>>N>>x0>>a>>b;
	cin>>Q;
	for(int i = 0; i < Q; ++i) {
		cin>>q[i];
		//0-based 이기 때문에 하나 늘려줌
		q[i]++;
		//쿼리의 결과가 될 수 있는 값의 범위는 [0,MOD) 이다
		lr[i] = {0, MOD-1};
	}
	//쿼리 오름차순 정렬 : 쿼리의 결과도 오름차순(단조증가)으로 정렬될 것
	sort(q, q+Q);
}

void solve() {
	while(true) {
		bool flag = false;
		fill(psum, psum+MAX, 0);

		for(int i = 0; i < Q; ++i) {
			if(lr[i].first <= lr[i].second) {
				//쿼리를 입력받고 정렬했기 때문에 mid값들도 단조증가한다 (mid에 대해 이분탐색 가능)
				mid[i] = (lr[i].first + lr[i].second)/2;
				flag = true;
			}
		}
		if(!flag) break;

		ll temp = x0;
		for(int i = 0; i < N; ++i) {
			//temp : X[i]
			//idx : X[i]가 mid에 대해 몇 번째로 큰 수인지 ([0, q]의 값을 가질 수 있다)
			int idx = lower_bound(mid, mid+Q, temp) - mid;
			psum[idx]++;
			temp = (temp * a + b) % MOD;
		}

		for(int i = 1; i < Q; ++i) psum[i] += psum[i-1];

		for(int i = 0; i < Q; ++i) {
			if(psum[i] >= q[i]) lr[i].second = mid[i]-1;
			else lr[i].first = mid[i]+1;
		}
	}

	ll result = 0;
	for(int i = 0; i < Q; ++i) result += lr[i].first;
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}