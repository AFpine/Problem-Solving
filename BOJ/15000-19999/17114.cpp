#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
// typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1010101;

struct tomato {
	int dim[15];
};

int dim[15], pdim[15];
int dist[MAX];
bool invalid[MAX];
queue<tomato> Q;

int calculate(tomato a) {
	int ret = 0;
	for(int i = 11; i >= 2; --i) {
		ret += pdim[i] * (a.dim[i]-1);
	}
	ret += a.dim[1];
	return ret;
}

void bfs() {
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(int i = 1; i <= 11; ++i) {
			if(cur.dim[i] == 1) continue;
			tomato nt = cur;
			nt.dim[i] -= 1;

			int nxt = calculate(nt);
			if(invalid[nxt] || dist[nxt] != -1) continue;
			dist[nxt] = dist[calculate(cur)] + 1;
			Q.push(nt);
		}
		for(int i = 1; i <= 11; ++i) {
			if(cur.dim[i] == dim[i]) continue;

			tomato nt = cur;
			nt.dim[i] += 1;

			int nxt = calculate(nt);
			if(invalid[nxt] || dist[nxt] != -1) continue;
			dist[nxt] = dist[calculate(cur)] + 1;
			Q.push(nt);
		}
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

	for(int i = 1; i <= 11; ++i) cin>>dim[i];
	pdim[1] = 1;
	for(int i = 2; i <= 11; ++i) {
		pdim[i] = pdim[i-1] * dim[i-1];
		// cout<<pdim[i]<<" ";
	}
	// cout<<'\n';

	for(int i1 = 1; i1 <= dim[11]; ++i1) {
		for(int i2 = 1; i2 <= dim[10]; ++i2) {
			for(int i3 = 1; i3 <= dim[9]; ++i3) {
				for(int i4 = 1; i4 <= dim[8]; ++i4) {
					for(int i5 = 1; i5 <= dim[7]; ++i5) {
						for(int i6 = 1; i6 <= dim[6]; ++i6) {
							for(int i7 = 1; i7 <= dim[5]; ++i7) {
								for(int i8 = 1; i8 <= dim[4]; ++i8) {
									for(int i9 = 1; i9 <= dim[3]; ++i9) {
										for(int i10 = 1; i10 <= dim[2]; ++i10) {
											for(int i11 = 1; i11 <= dim[1]; ++i11) {
												int t;
												int idx = (i1-1) * pdim[11] + (i2-1) * pdim[10] + (i3-1) * pdim[9] + (i4-1) * pdim[8] + (i5-1) * pdim[7] + (i6-1) * pdim[6] + (i7-1) * pdim[5] + (i8-1) * pdim[4] + (i9-1) * pdim[3] + (i10-1) * pdim[2] + i11;
												cin>>t;
												if(t == 1) {
													// cout<<idx<<" "<<i10<<'\n';
													dist[idx] = 0;
													tomato T;
													T.dim[1] = i11;
													T.dim[2] = i10;
													T.dim[3] = i9;
													T.dim[4] = i8;
													T.dim[5] = i7;
													T.dim[6] = i6;
													T.dim[7] = i5;
													T.dim[8] = i4;
													T.dim[9] = i3;
													T.dim[10] = i2;
													T.dim[11] = i1;
													Q.push(T);
												}
												else if(t == 0) dist[idx] = -1;
												else {
													invalid[idx] = true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	bfs();

	int total = 1;
	for(int i = 1; i <= 11; ++i) {
		total *= dim[i];
	}

	bool inval = false;
	int result = 0;
	for(int i = 1; i <= total; ++i) {
		if(dist[i] == -1) inval = true;
		result = max(result, dist[i]);
	}

	if(inval) cout<<"-1";
	else cout<<result;

	// cout<<'\n'<<result<<'\n';

	return 0;
}