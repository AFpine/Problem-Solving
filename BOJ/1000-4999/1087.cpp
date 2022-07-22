#include <bits/stdc++.h>
 
// 1087 쥐 잡기
 
// update 220722

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1005;

int N;
pdd direc[MAX], velo[MAX];

double distance(double t) {
	double maxx = -INF, minx = INF, maxy = -INF, miny = INF;
	for(int i = 1; i <= N; ++i) {
		maxx = max(maxx, direc[i].first + velo[i].first * t);
		minx = min(minx, direc[i].first + velo[i].first * t);
		maxy = max(maxy, direc[i].second + velo[i].second * t);
		miny = min(miny, direc[i].second + velo[i].second * t);
	}
	return max(abs(maxx-minx), abs(maxy-miny));
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>direc[i].first>>direc[i].second>>velo[i].first>>velo[i].second;
	}
}

void solve() {
	double l = 0, r = 2005;
	for(int it = 0; it < 10000; ++it) {
		double p = (2.0*l + r) / 3.0;
		double q = (l + 2.0*r) / 3.0;
		if(distance(p) <= distance(q)) r = q;
		else l = p;
	}
	// cout<<l<<" "<<r;
	cout<<distance((l+r)/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout<<fixed;
	cout.precision(20);

	input();
	solve();
 
	return 0;
}