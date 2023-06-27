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
const long long MOD = 1e9+9;
const int MAX = 202020;

struct LINE {
	int idx, x, open;
};

int N;
vector<pll> v;
vector<LINE> line;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	v.resize(N);
	for(int i = 0; i < N; ++i) cin>>v[i].first>>v[i].second;

	int cnt = 0;
	int start = 0;

	ll mx = INF;
	for(int i = 0; i < N; ++i) {
		if((v[i].second * v[(i+1)%N].second) < 0 && v[i].first < mx) {
			mx = v[i].first;
			start = i;
		}
	}

	for(int i = start; i <= start+N-1; i += 2) {
		if((v[i%N].second * v[(i+1)%N].second) > 0) continue;

		if(v[i%N].second < v[(i+1)%N].second) {
			line.push_back(LINE({cnt/2, v[i%N].first, 0}));
		}
		else {
			if(line.back().x > v[i%N].first) {
				line.back().open = 1;
				line.push_back(LINE({cnt/2, v[i%N].first, 0}));
			}
			else {
				line.push_back(LINE({cnt/2, v[i%N].first, 1}));
			}
		}
		cnt++;
	}

	sort(line.begin(), line.end(), [](LINE a, LINE b) {
		return a.x < b.x;
	});
	
	stack<int> st;
	int prv = -1;
	int res1 = 0, res2 = 0;
	for(auto &l : line) {
		if(l.open == 0) {
			if(st.empty()) res1++;
			st.push(l.idx);
			prv = l.idx;
		}
		else {
			if(prv == l.idx) res2++;
			st.pop();
		}
	}

	cout<<res1<<" "<<res2<<'\n';

	return 0;
}