#include <bits/stdc++.h>

// 8217 유성

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
const int MAX = 300005;
const long long MOD = 1e9+7;

int N, M, Q;
ll p[MAX];
vector<int> o[MAX];
tuple<int, int, ll> q[MAX];
int ql[MAX], qr[MAX];
vector<int> G[MAX];
int result[MAX];

ll tree[4*MAX];

void update(ll pos, ll k) {
	while(pos <= M) {
		tree[pos] += k;
		pos += (pos&(-pos));
	}
}

ll sum(int pos) {
	ll ret = 0;
	while(pos > 0) {
		ret += tree[pos];
		pos -= (pos&(-pos));
	}
	return ret;
}

void input() {
	cin>>N>>M;
	//o[i] : i번째 나라가 담당하는 구역
	for(int i = 1; i <= M; ++i) {
		int t;
		cin>>t;
		o[t].push_back(i);
	}
	//p[i] : i번째 나라가 채워야하는 최소 유성우 값
	for(int i = 1; i <= N; ++i) cin>>p[i];
	cin>>Q;
	for(int i = 1; i <= Q; ++i) {
		int l, r;
		ll a;
		cin>>l>>r>>a;
		q[i] = {l, r, a};
	}
}

void solve() {
	fill(ql, ql+MAX, 1);
	fill(qr, qr+MAX, Q);
	while(true) {
		bool flag = false;
		for(int i = 0; i <= Q; ++i) {
			G[i].clear();
		}
		for(int i = 1; i <= N; ++i) {
			if(ql[i] <= qr[i]) {
				flag = true;
				G[(ql[i]+qr[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		fill(tree, tree+4*MAX, 0);
		for(int i = 1; i <= Q; ++i) {
			int l, r;
			ll a;
			tie(l, r, a) = q[i];

			if(l <= r) {
				update(l, a);
				update(r+1, -a);
			}
			else {
				update(1, a);
				update(r+1, -a);
				update(l, a);
			}
			
			for(auto &j : G[i]) {
				ll temp = 0;
				for(auto &t : o[j]) {
					temp += sum(t);
					if(temp >= p[j]) break;
				}
				if(temp >= p[j]) {
					result[j] = i;
					qr[j] = i-1;
				}
				else {
					ql[j] = i+1;
				}
			}
		}
	}
	for(int i = 1; i <= N; ++i) {
		if(result[i] == 0) cout<<"NIE\n";
		else cout<<result[i]<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}