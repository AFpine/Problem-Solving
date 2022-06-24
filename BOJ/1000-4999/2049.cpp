#include <bits/stdc++.h>

// 2049 가장 먼 두 점

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

ll rotatingCalipers(vector<pii> h)
{
	int n = h.size();
	int pl = 0, pr = 0;
	
	for(int i = 0;i<n;++i)
	{
		if(h[pl].x > h[i].x) pl = i;
		if(h[pr].x < h[i].x) pr = i;
	}
	
	ll result = distance(h[pl], h[pr]);

	for(int i = 0;i<n;++i)
	{
		if(ccw({0,0}, h[(pl+1)%n]-h[pl], h[pr]-h[(pr+1)%n]) > 0)
		{
			pl = (pl+1) % n;
		}
		else
		{
			pr = (pr+1) % n;
		}
		if(distance(h[pl],h[pr]) > result)
		{
			result = distance(h[pl],h[pr]);
		}
	}
	return result;
}

int T,N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// cout<<fixed;
	// cout.precision(12);

	vector<pii> v;

	cin>>N;

	for(int i = 0;i<N;++i)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	
    auto h = getConvexHull(v);
	
    cout<<rotatingCalipers(h);
	
    return 0;
}