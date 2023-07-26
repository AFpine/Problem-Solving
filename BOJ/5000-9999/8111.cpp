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

int K;
bool visited[MAX];
pii prv[MAX];

void solve(int n) {
	fill(visited, visited+MAX, false);
	for(int i = 0; i < MAX; ++i) prv[i] = {-1, 1};
	queue<int> Q;

	visited[1] = true;
	Q.push(1);
	
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if(cur == 0) break;
		
		int t = (cur*10) % n;
		if(visited[t] == false) {
			visited[t] = true;
			prv[t].first = cur;
			prv[t].second = 0;
			Q.push(t);
		}
		
		t = (cur*10+1) % n;
		if(visited[t] == false) {
			visited[t] = true;
			prv[t].first = cur;
			prv[t].second = 1;
			Q.push(t);
		}
	}
	if(visited[0] == false) {
		cout<<"BARK\n";
	}
	else {
		vector<int> result;
		int cur = 0;
		while(cur != -1) {
			result.push_back(prv[cur].second);
			cur = prv[cur].first;
		}
		reverse(result.begin(), result.end());
		for(auto &i : result) cout<<i;
		cout<<'\n';
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>K;
	while(K--) {
		int n;
		cin>>n;
		solve(n);
	}

	return 0;
}