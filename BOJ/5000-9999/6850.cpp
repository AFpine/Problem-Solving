#include <bits/stdc++.h>

// 6850 Cows

// update 220608

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;
const int MOD = 1e9+7;

struct Point
{
	long long x,y;
	long long p{1},q;

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

int N;
Point p[MAX];
stack<int> st;
vector<int> CH;

long long ccw(const Point &a, const Point &b, const Point &c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>p[i].x>>p[i].y;
	}
	
	sort(p+1,p+1+N);

	for(int i = 2;i<=N;++i)
	{
		p[i].p = p[i].x - p[1].x;
		p[i].q = p[i].y - p[1].y;
	}

	sort(p+2,p+1+N);

	if(N <= 1)
	{
		cout<<"0";
	}

	st.push(1);
	st.push(2);
	int next = 3;

	while(next <= N)
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

	while(!st.empty())
	{
		CH.push_back(st.top());
		st.pop();
	}

	long long result = 0;
	
	for(int i = 0;i<CH.size();++i)
	{
		result += 1LL*(p[CH[i]].x + p[CH[(i+1)%(CH.size())]].x) * (p[CH[i]].y - p[CH[(i+1)%(CH.size())]].y);
	}
	result = abs(result)/2;
	cout<<abs(result)/50;

	return 0;
}


