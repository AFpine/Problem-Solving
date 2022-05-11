#include <bits/stdc++.h>

// 16491 대피소 찾기

// update 220511

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

struct Point
{
	double x,y;
};

struct Line
{
	Point p1,p2;
};

int N;
Point robot[11];
Point shelter[11];
pair<Line,int> line[11];
bool selected[11];

bool pointCompare(Point &p1, Point &p2)
{//p2 is on righthandside of p1
	if(p1.x == p2.x)
	{
		if(p1.y <= p2.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(p1.x < p2.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ccw(Point &p1, Point &p2, Point &p3)
{
	double result = (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
	if(result > 0)
	{
		return 1;
	}
	else if(result < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

bool lineIntersection(Line &l1, Line &l2)
{
	int tmp1 = ccw(l1.p1,l1.p2,l2.p1)*ccw(l1.p1,l1.p2,l2.p2);
	int tmp2 = ccw(l2.p1,l2.p2,l1.p1)*ccw(l2.p1,l2.p2,l1.p2);
	if(tmp1 == 0 && tmp2 == 0)
	{
		if(pointCompare(l1.p2,l1.p1))
		{
			swap(l1.p1,l1.p2);
		}
		if(pointCompare(l2.p2,l2.p1))
		{
			swap(l2.p1,l2.p2);
		}
		if(pointCompare(l1.p2,l2.p2) && pointCompare(l2.p1,l1.p2))
		{
			return true;
		}
		else if(pointCompare(l2.p2,l1.p2) && pointCompare(l1.p1,l2.p2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(tmp1 <= 0 && tmp2 <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool recursion(int cur, int n)
{
	Line tmp;
	if(n == N)
	{
		for(int i = 1;i<=N;++i)
		{
			cout<<line[i].second<<'\n';
		}
		return true;
	}
	for(int i = 1;i<=N;++i)
	{
		bool flag = true;
		if(selected[i] == true)
		{
			continue;
		}
		tmp = {robot[cur],shelter[i]};
		for(int j = 1;j<=n;++j)
		{
			if(lineIntersection(tmp,line[j].first))
			{
				flag = false;
				break;
			}
		}
		if(flag == false)
		{
			continue;
		}
		selected[i] = true;
		line[n+1].first = tmp;
		line[n+1].second = i;
		if(recursion(cur+1,n+1))
		{
			return true;
		}
		selected[i] = false;
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	
	for(int i = 1;i<=N;++i)
	{
		cin>>robot[i].x>>robot[i].y;
	}
	for(int i = 1;i<=N;++i)
	{
		cin>>shelter[i].x>>shelter[i].y;
	}

	recursion(1,0);

	return 0;
}


