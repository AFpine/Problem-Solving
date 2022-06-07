#include <bits/stdc++.h>

// 7420 맹독 방벽

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

int N,L;
Point p[MAX];
stack<int> st;
vector<int> convexHullV;
double result = 0;

long long ccw(const Point &a, const Point &b, const Point &c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

double distance(const Point &a, const Point &b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>L;

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
		convexHullV.push_back(st.top());
		st.pop();
	}

	int size = convexHullV.size();
	for(int i = 0;i<size-1;++i)
	{
		result += distance(p[convexHullV[i]],p[convexHullV[i+1]]);
	}
	result += distance(p[convexHullV[size-1]],p[convexHullV[0]]);

	result += 2*L*M_PI;

	result = round(result);

	cout<<result;

	return 0;
}


