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
const int MAX = 10005;

int N;
vector<int> v[MAX];
priority_queue<int> pq;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		int p, d;
		cin>>p>>d;
		v[d].push_back(p);
	}

	int result = 0;
	for(int i = 10000; i >= 1; --i) {
		for(auto &e : v[i]) pq.push(e);
		if(!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout<<result;
	
	return 0;
}