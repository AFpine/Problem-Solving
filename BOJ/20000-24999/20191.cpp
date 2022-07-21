#include <bits/stdc++.h>

// 20191 줄임말

// update 220721
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 100005;

string S, T;
vector<int> alpidx[26];

void input() {
	cin>>S>>T;
	// alpidx[i] : T에서 i문자가 등장하는 위치를 저장 (오름차순)
	for(int i = 0; i < T.length(); ++i) alpidx[T[i]-'a'].push_back(i);
}

void solve() {
	for(int i = 0; i < S.length(); ++i) {
		if(alpidx[S[i]-'a'].empty()) {
			cout<<"-1";
			return;
		}
	}

	int idx = -1, result = 1;
	for(int i = 0; i < S.length(); ++i) {
		// 현재 찾아야 하는 S[i]의 (idx보다 뒤에 있는) 위치를 이분탐색으로 찾는다 
		auto it = upper_bound(alpidx[S[i]-'a'].begin(), alpidx[S[i]-'a'].end(), idx);
		// T의 idx번째 단어를 사용하고 있는데, idx보다 뒤에 S[i]가 존재하지 않는다면 
		// T가 한 번 더 반복되어야 한다 (result 증가)
		if(it == alpidx[S[i]-'a'].end()) {
			result++;
			idx = -1;
			// 새로운 T 문자열이 뒤에 붙었으므로, 현재의 S[i]의 위치를 다시 이분탐색으로 찾는다
			it = upper_bound(alpidx[S[i]-'a'].begin(), alpidx[S[i]-'a'].end(), idx);
		}
		// 현재 T의 idx번째 단어까지 사용함
		idx = *it;
	}

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