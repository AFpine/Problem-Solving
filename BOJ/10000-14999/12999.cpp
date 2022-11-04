#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 12999

// 221103

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
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 101010;
const int D = 100001;

int sq = 317;

struct se {
	int s, e, idx;
	bool operator<(const se& rhs) const {
		if (s / sq != rhs.s / sq) return s / sq < rhs.s / sq;
		return e < rhs.e;
	}
};

int N, Q, arr[MAX], cnt1[2*MAX], cnt2[MAX], cur = 0;
vector<se> q;
vector<int> ans;

void input() {
	cin>>N>>Q;
	for(int i = 1; i <= N; ++i) { cin>>arr[i]; arr[i] += D; }
	
	q.resize(Q); ans.resize(Q);
	for(int i = 0; i < Q; ++i) {
		cin>>q[i].s>>q[i].e;
		q[i].idx = i;
	}

	sort(all(q));
}

void add(int idx) {
	if(cnt1[arr[idx]]) cnt2[cnt1[arr[idx]]]--;
	cnt1[arr[idx]]++;
	cnt2[cnt1[arr[idx]]]++;
	if(cnt2[cur+1] > 0) cur++;
}

void del(int idx) {
	cnt2[cnt1[arr[idx]]]--;
	cnt1[arr[idx]]--;
	cnt2[cnt1[arr[idx]]]++;
	if(cnt2[cur] <= 0) cur--;
}

int query() {
	return cur;
}

void f() {
	sq = 317;
	int s = q[0].s, e = q[0].e;
	for(int i = s; i <= e; ++i) {
		if(cnt1[arr[i]]) cnt2[cnt1[arr[i]]]--;
		cnt1[arr[i]]++;
		cnt2[cnt1[arr[i]]]++;
		if(cnt2[cur+1] > 0) cur++;
	}
	ans[q[0].idx] = query();

	for (int i = 1; i < q.size(); i++) {
		while (q[i].s < s) add(--s);
		while (e < q[i].e) add(++e);
		while (s < q[i].s) del(s++);
		while (q[i].e < e) del(e--);
		ans[q[i].idx] = query();
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	
	f();
	
	for(auto &i : ans) cout<<i<<"\n";
	
	return 0;
}
