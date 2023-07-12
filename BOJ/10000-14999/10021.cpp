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
const int MAX = 2020;

struct Edge {
	int w, u, v;
};

pii field[MAX];
int N, C, uf[MAX];
ll result;
vector<Edge> a;

int distance(pii a, pii b) {
	return (a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second);
}

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf, uf+MAX, -1);

	cin>>N>>C;
	for(int i = 1; i <= N; ++i) {
		cin>>field[i].first>>field[i].second;
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = i+1; j <= N; ++j) {
			a.push_back({ distance(field[i], field[j]), i, j });
		}
	}

	sort(a.begin(), a.end(), [](Edge a, Edge b) {
		return a.w < b.w;
	});
	for(auto &i : a) {
		if(find(i.u) == find(i.v)) continue;
		if(i.w < C) continue;
		merge(i.u, i.v);
		result += i.w;
	}
	
	int r = find(1);
	bool invalid = false;
	for(int i = 2; i <= N; ++i) {
		if(find(i) != r) invalid = true;
	}

	if(invalid) cout<<"-1";
	else cout<<result;

	return 0;
}