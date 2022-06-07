#include <bits/stdc++.h>

// 1708 볼록 껍질

// update 220606

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int MOD = 1e9+7;

struct Point
{
	int x,y;
	int p,q;

	bool operator<(const Point &O)
	{
		if(1LL*q*O.p != 1LL*p*O.q)
		{
			return 1LL*q*O.p < 1LL*p*O.q;
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

int N;
Point point[MAX];
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		int x,y;
		cin>>x>>y;
		point[i] = Point({x,y,1,0});
	}

	sort(point+1,point+1+N);

	for(int i = 2;i<=N;++i)
	{
		point[i].p = point[i].x - point[1].x;
		point[i].q = point[i].y - point[1].y;
	}

	sort(point+2,point+1+N);

	int next = 3;
	st.push(1);
	st.push(2);

	while(next <= N)
	{
		while(st.size() >= 2)
		{
			int first, second;
			first = st.top();
			st.pop();
			second = st.top();

			if(ccw(point[second],point[first],point[next]) > 0)
			{
				st.push(first);
				break;
			}
		}
		
		st.push(next++);
	}

	cout<<st.size();

	return 0;
}

