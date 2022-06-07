#include <bits/stdc++.h>

// 2254 감옥 건설

// update 220607

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const int MOD = 1e9+7;

struct Point
{
	long long x,y;
	long long p,q;

	bool operator<(const Point &O)
	{
		if(q*O.p != p*O.q)
		{
			return q*O.p < p*O.q;
		}
		if(y != O.y)
		{
			return y < O.y;
		}
		else
		{
			return x < O.x;
		}
	}
};

long long ccw(const Point &a, const Point &b, const Point &c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int checkCCW(long long &a)
{
	if(a > 0)
	{
		return 1;
	}
	else if(a < 0)
	{
		return -1;
	}
	else 
	{
		return 0;
	}
}

int N;
Point prison = {0,0,0,0};
vector<Point> p;
set<int> convexHullSet;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	cin>>prison.x>>prison.y;

	for(int i = 1;i<=N;++i)
	{
		long long x,y;
		cin>>x>>y;
		p.push_back({x,y,1,0});
	}

	while(true)
	{
		if(p.size() <= 1)
		{
			break;
		}
		for(int i = 0;i<p.size();++i)
		{
			p[i].p = 1;
			p[i].q = 0;
		}
		sort(p.begin(),p.end());

		for(int i = 1;i<p.size();++i)
		{
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}

		sort(p.begin()+1,p.end());

		stack<int> st;
		st.push(0);
		st.push(1);
		int next = 2;

		while(next < N)
		{
			while(st.size() >= 2)
			{
				int first, second;
				first = st.top();
				st.pop();
				second = st.top();

				if(ccw(p[second],p[first],p[next]) > 0)
				{
					st.push(first);
					break;
				}
			}
			st.push(next++);
		}

		N -= st.size();
		
		bool flag = true;
		long long nowCCW = 0, prevCCW = INF;
		while(st.size() >= 2)
		{
			int first, second;
			first = st.top();
			st.pop();
			second = st.top();
			
			nowCCW = ccw(p[second],p[first],prison);
			if(prevCCW == INF)
			{
				p.erase(p.begin()+first);
				prevCCW = nowCCW;
				continue;
			}
			else if(checkCCW(nowCCW) == checkCCW(prevCCW))
			{
				p.erase(p.begin()+first);
				prevCCW = nowCCW;
				continue;
			}
			else
			{
				p.erase(p.begin()+first);
				flag = false;
				break;
			}
		}
		while(!st.empty())
		{
			p.erase(p.begin()+st.top());
			st.pop();
		}

		if(flag)
		{
			result++;
		}
		else
		{
			break;
		}
	}

	cout<<result;


	return 0;
}

