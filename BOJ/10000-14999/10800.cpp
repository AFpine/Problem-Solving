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

struct BALL {
	int idx, color, size;
	vector<int> cnt;
};

int N;
vector<BALL> v, nv;
ll total, tmp;
ll cv[MAX], result[MAX];

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
	for(int i = 0; i < N; ++i) {
		v[i].idx = i;
		v[i].cnt.push_back(i);
		cin>>v[i].color>>v[i].size;
	}
	sort(v.begin(), v.end(), [](BALL a, BALL b) {
		if(a.size == b.size) return a.color < b.color;
		return a.size < b.size;
	});

	for(auto &cur : v) {
		if(!nv.empty() && nv.back().color == cur.color && nv.back().size == cur.size) {
			nv.back().cnt.push_back(cur.idx);
		}
		else nv.push_back(cur);
	}

	int cursize = -1;
	for(auto &b : nv) {
		if(b.size > cursize) {
			total += tmp;
			tmp = 0;
			cursize = b.size;
		}
		for(auto &i : b.cnt) {
			result[i] = total - cv[b.color];
		}
		
		tmp += (1LL * b.size * b.cnt.size());
		cv[b.color] += (1LL * b.size * b.cnt.size());
	}

	for(int i = 0; i < N; ++i) cout<<result[i]<<'\n';

	return 0;
}