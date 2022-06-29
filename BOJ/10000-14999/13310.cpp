#include <bits/stdc++.h>

// 13310 먼 별

// update 220629

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 30005;
const long long MOD = 1e9+7;

pii operator-(pii a, pii b) {
	return {a.x-b.x, a.y-b.y};
}

ll ccw(pii o, pii a, pii b) {
	return 1LL*(a.x-o.x)*(b.y-o.y) - 1LL*(a.y-o.y)*(b.x-o.x);
}

ll distance(pii a, pii b) {
	return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y);
}

vector<pii> getConvexHull(vector<pii> p) {
	int n = p.size();
	int k = 0;
	if(n <= 3) {
		return p;
	}
	
	vector<pii> ret;

	sort(p.begin(), p.end());
	for(int i = 0;i<n;++i) {
		while(k >= 2 && ccw(ret[k-2], ret[k-1], p[i]) <= 0) {
			ret.pop_back();
			k--;
		}
		ret.push_back(p[i]);
		k++;
	}
	for(int i = n-1, t = k+1; i>=0;--i) {
		while(k >= t && ccw(ret[k-2], ret[k-1], p[i-1]) <= 0) {
			ret.pop_back();
			k--;
		}
		ret.push_back(p[i-1]);
		k++;
	}
	ret.pop_back();
	
	return ret;
}

ll rotatingCalipers(vector<pii> h) {
	int n = h.size();
	int pl = 0, pr = 0;

	for(int i = 0;i<n;++i) {
		if(h[i].x > h[pr].x) pr = i;
		if(h[i].x < h[pl].x) pl = i;
	}
	
	ll ret = distance(h[pl], h[pr]);

	for(int i = 0;i<2*n;++i) {
		if(ccw({0,0}, h[(pl+1)%n]-h[pl], h[pr]-h[(pr+1)%n]) > 0) {
			pl = (pl+1)%n;
		}
		else {
			pr = (pr+1)%n;
		}
		if(distance(h[pl], h[pr]) > ret) {
			ret = distance(h[pl], h[pr]);
		}
	}

	return ret;
}

int N, T;
pii originP[MAX];
pii velocity[MAX];

ll solve(ll m) {
	vector<pii> v;
	for(int i = 0;i<N;++i) {
		v.push_back({originP[i].x + m*(velocity[i].first), originP[i].y + m*(velocity[i].second)});
	}

	vector<pii> CH = getConvexHull(v);
	
	return rotatingCalipers(CH);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>T;

	for(int i = 0;i<N;++i) {
		cin>>originP[i].x>>originP[i].y>>velocity[i].first>>velocity[i].second;
	}

	ll l = 0, r = T;
	ll result = llINF;
	ll t = 0;

	while(r-l >= 3) {
		ll p = (2*l+r)/3;
		ll q = (l+2*r)/3;
		ll pdist = solve(p);
		ll qdist = solve(q);

		if(pdist <= qdist) {
			if(result > pdist) {
				result = pdist;
				t = p;
			}
			r = q;
		}
		else {
			if(result > qdist) {
				result = qdist;
				t = q;
			}
			l = p;
		}
	}

	for(int i = r;i>=l;--i) {
		if(result >= solve(i)) {
			result = solve(i);
			t = i;
		}
	}

	cout<<t<<'\n'<<result;

	return 0;
}