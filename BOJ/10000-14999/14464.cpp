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
const int MAX = 20202;

struct S {
	pii T;
	int priority;
};

int C, N;
vector<S> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>C>>N;
	for(int i = 1; i <= C; ++i) {
		int t;
		cin>>t;
		v.push_back({ {t, 0}, 1 });
	}
	for(int i = 1; i <= N; ++i) {
		int a, b;
		cin>>a>>b;
		v.push_back({ {a, b}, 0 });
	}

	sort(v.begin(), v.end(), [](S a, S b) {
		if(a.T.first == b.T.first) {
			return a.priority < b.priority;
		}
		return a.T.first < b.T.first;
	});

	int result = 0;
	for(auto &i : v) {
		if(i.priority == 0) {
			pq.push(i.T.second);
		}
		else {
			while(!pq.empty()) {
				if(pq.top() < i.T.first) {
					pq.pop();
					continue;
				}
				else {
					pq.pop();
					result++;
					break;
				}
			}
		}
	}
	cout<<result;

	return 0;
}