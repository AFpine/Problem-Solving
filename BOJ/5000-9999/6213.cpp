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
const int MAX = 50505;

int flag;  // array size
struct Seg {  // 1-indexed
	vector<ll> t;
	void build1(int n) {
		for (flag = 1; flag < n; flag <<= 1);
		t.resize(2 * flag);
		fill(t.begin(), t.end(), -1);
	}
	void build2(int n) {
		for (flag = 1; flag < n; flag <<= 1);
		t.resize(2 * flag);
		fill(t.begin(), t.end(), INF);
	}
	void modify1(int p, ll value) {  // set value at position p
		for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	void modify2(int p, ll value) {  // set value at position p
		for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
	}
	ll query1(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];
		int mid = (nl + nr) / 2;
		return max(query1(l, r, n << 1, nl, mid), query1(l, r, n << 1 | 1, mid + 1, nr));
	}
	ll query2(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
		if (r < nl || nr < l) return INF;
		if (l <= nl && nr <= r) return t[n];
		int mid = (nl + nr) / 2;
		return min(query2(l, r, n << 1, nl, mid), query2(l, r, n << 1 | 1, mid + 1, nr));
	}
};

int N, Q;
Seg mxtree, mntree;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>Q;

	mxtree.build1(N);
	mntree.build2(N);

	for(int i = 1; i <= N; ++i) {
		int h;
		cin>>h;
		mxtree.modify1(i, h);
		mntree.modify2(i, h);
	}

	for(int i = 1; i <= Q; ++i) {
		int A, B;
		cin>>A>>B;
		cout<<mxtree.query1(A, B)-mntree.query2(A, B)<<'\n';		
	}
	
	return 0;
}