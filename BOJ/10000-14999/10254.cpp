#include <bits/stdc++.h>

// 10254 고속도로

// update 220624

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2005;
const long long MOD = 1e9+7;

pii operator-(pii a, pii b)
{
	return {a.x-b.x, a.y-b.y};
}

ll ccw(pii a, pii b, pii c)
{// positive is ccw, negative is cw, o is collinear
	return 1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(b.y-a.y)*(c.x-a.x);
}

ll distance(pii a, pii b)
{
	return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y);
}

bool chk(pii s, pii e, pii ss, pii ee)
{
	pii t = {e.x-s.x, e.y-s.y};
	pii tt = {ee.x-ss.x, ee.y-ss.y};
	return ccw({0,0},t,tt) >= 0;
}

vector<pii> getConvexHull(vector<pii> p)
{
	int n = p.size();
	int k = 0;

	vector<pii> result;

	sort(p.begin(),p.end());
	for(int i = 0;i<n;++i)
	{
		while(k >= 2 && ccw(result[k-2],result[k-1],p[i]) <= 0)
		{
			result.pop_back();
			--k;
		}
		result.push_back(p[i]);
		++k;
	}

	for(int i = n-1, t = k+1; i>0;--i)
	{
		while(k >= t && ccw(result[k-2],result[k-1],p[i-1]) <= 0)
		{
			result.pop_back();
			k--;
		}
		result.push_back(p[i-1]);
		k++;
	}
	result.pop_back();

	return result;
}

pair<pii,pii> rotatingCalipers(vector<pii> h)
{
	pair<pii,pii> ret = {{0,0},{0,0}};

	ll maxDist = 0;
	int pt = 0;
	for(int i = 0;i<h.size();++i)
	{
		ll now;
		while(pt+1 < h.size() && chk(h[i],h[i+1],h[pt],h[pt+1]))
		{
			now = distance(h[i],h[pt]);
			if(now > maxDist)
			{
				maxDist = now;
				ret = {h[i],h[pt]};
			}
			pt++;
		}
		now = distance(h[i],h[pt]);
		if(now > maxDist)
		{
			maxDist = now;
			ret = {h[i],h[pt]};
		}
	}

	return ret;
}

int T,N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// cout<<fixed;
	// cout.precision(12);

	cin>>T;

	while(T--)
	{
		vector<pii> v;
		cin>>N;

		for(int i = 0;i<N;++i)
		{
			int a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}

		auto h = getConvexHull(v);

		auto result = rotatingCalipers(h);

		cout<<result.first.first<<" "<<result.first.second<<" "<<result.second.first<<" "<<result.second.second<<"\n";

	}

	return 0;
}