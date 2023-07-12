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
const int MAX = 101010;

int T, N, L, k;
pii ant[MAX];
vector<pii> pos, neg;

int dist(pii a) {
	if(a.second > 0) return L - a.first;
	else return a.first;
}

int solve(int k) {
	int l = -1, r = sz(neg), t = 0, res;
	if(ant[k].second < 0) {
		r = (int)(lower_bound(neg.begin(), neg.end(), ant[k]) - neg.begin());
		res = r;
		t = 0;
	}
	else {
		l = (int)(lower_bound(pos.begin(), pos.end(), ant[k]) - pos.begin());
		res = l;
		t = 1;
	}
	while(true) {
		if((l < (sz(pos)-1)) && (t == 0) && (pos[l+1].first < neg[r].first)) {
			l++;
			res = l;
			t = 1;
		}
		else if((r > 0) && (t == 1) && (pos[l].first < neg[r-1].first)) {
			r--;
			res = r;
			t = 0;
		}
		else break;
	}
	if(t == 0) return neg[res].second;
	else return pos[res].second;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--) {
		pos.clear();
		neg.clear();

		cin>>N>>L>>k;
		for(int i = 1; i <= N; ++i) {
			cin>>ant[i].first>>ant[i].second;
			if(ant[i].second > 0) pos.push_back(ant[i]);
			else neg.push_back(ant[i]);
		}
		sort(ant+1, ant+1+N, [](pii a, pii b) {
			return dist(a) < dist(b);
		});
		int res = solve(k);
		if(k > 1 && dist(ant[k]) == dist(ant[k-1])) {
			int tmp = solve(k-1);
			res = max(res, tmp);	
		}
		else if(k < N && dist(ant[k]) == dist(ant[k+1])) {
			int tmp = solve(k+1);
			res = min(res, tmp);
		}
		cout<<res<<"\n";
	}

	return 0;
}