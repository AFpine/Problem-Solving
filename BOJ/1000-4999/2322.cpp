#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2322

// 221101

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

int N;
pair<long long, int> arr[MAX];
bool check[MAX];
ll ans = 0;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i].first;
		arr[i].second = i;
	}
	sort(arr+1, arr+1+N);

	//순열 사이클 분할
	for(int i = 1; i <= N; ++i) {
		if(check[i]) continue;
		ll cnt = 0;		//cnt : 사이클 크기
		//이 순열 안에서 순서를 바꾸는 행위는 cnt-1번 일어난다 (즉 값을 2cnt-2번 더해야한다)
		for(int j = i; !check[j]; j = arr[j].second) {
			check[j] = true;
			ans += arr[j].first;
			cnt++;
		}
		//i 번째 값(이 사이클 내에서 가장 가중치가 작은 값)을 이용해 나머지 값들은 자기 위치를 찾아간 상태와
		//이 순열 안에서 제일 작은 값을 이용해 자리를 찾게 한 상태의 비용 중 작은 값을 선택하여 더함
		ans += min(arr[1].first*(cnt+1) + arr[i].first, arr[i].first*(cnt-2));
	}

	cout<<ans;

	return 0;
}
