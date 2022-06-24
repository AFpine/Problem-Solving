#include <bits/stdc++.h>

// 18252 별이 빛나는 밤에

// update 220624

using namespace std;
typedef long long ll;
typedef pair<double,double> pii;
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

double ccw(pii a, pii b, pii c)
{// positive is ccw, negative is cw, o is collinear
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

double distance(pii a, pii b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

vector<pii> getConvexHull(vector<pii> p)
{
	int n = p.size();
	int k = 0;

	if(n <= 3)
	{
		return p;
	}
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

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed;
	cout.precision(12);

	vector<pii> v, chv;
	
	cin>>N;

	pii u,d;

	cin>>u.x>>u.y>>d.x>>d.y;
	v.push_back(u);
	v.push_back(d);

	for(int i = 0;i<N;++i)
	{
		int ty, tx1, tx2;
		cin>>ty>>tx1>>tx2;
		if(ccw(d,u,{tx1,ty}) > 0 && ccw(d,u,{tx2,ty}) > 0)
		{
			v.push_back({tx2,ty});
		}
		else if(ccw(d,u,{tx1,ty}) < 0 && ccw(d,u,{tx2,ty}) < 0)
		{
			v.push_back({tx1,ty});
		}
		//else, this star can set collinear on u,d
	}

	chv = getConvexHull(v);
	int n = chv.size();

	//------여기 까지의 아이디어 스스로 생각해냄.

	int i = 0, j = 1, pt = 1;
	double result = 0, now = 0;
	while(i != n)
	{
		while(i != pt)
		{//i 하나를 기준으로 
			if(abs(ccw(chv[i], chv[j], chv[(pt+1)%n])) < now)
			{//(i,j,(pt+1)%n) 세 점이 이루는 넓이가 현재 최대값보다 작다면
				//j를 한 칸 옮겨본다
				j = (j+1) % n;
			}
			else
			{//아니라면 pt를 한 칸 옮긴다
				pt = (pt+1) % n;
			}

			now = abs(ccw(chv[i], chv[j], chv[pt]));
			result = max(result, now);
		}
		i++;
		j = (i+1) % n;
		pt = (j+1) % n;
	}

	cout<<result/2<<'\n';

	return 0;
}