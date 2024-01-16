#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int INF = 1e9;

int N, K;
set<int> s;
int arr[111];
queue<int> turn[111];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	
	int prv = -1;
	for(int i = 1; i <= K; ++i) {
		cin>>arr[i];
		turn[arr[i]].push(i);
	}

	int ans = 0;
	for(int i = 1; i <= K; ++i) {
		if(s.size() < N) s.insert(arr[i]);
		else if(s.find(arr[i]) == s.end()){
			int mord = -1;
			int idx = -1;
			for(auto &j : s) {
				if(turn[j].size() == 0) {
					idx = j;
					break;
				}
				else {
					if(turn[j].front() > mord) {
						mord = turn[j].front();
						idx = j;
					}
				}
			}
			s.erase(idx);
			s.insert(arr[i]);
			ans++;
		}
		turn[arr[i]].pop();
	}

	cout<<ans;
	
	return 0;
}