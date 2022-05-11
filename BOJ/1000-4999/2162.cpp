#include <bits/stdc++.h>

// 2162 선분 그룹

// update 220511

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int BINARY_MAX = 17;

struct Point
{
	double x,y;
};

struct Line
{
	Point p1,p2;
};

int N;
int p[3001];
Line line[3001];

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

int find(int a)
{
	if(p[a] < 0)
	{
		return a;
	}
	return p[a] = find(p[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)
	{
		return;
	}
	p[a] += p[b];
	p[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1;i<=3000;++i)
	{
		p[i] = -1;
	}

	int maxval = -1;
	int groupnum = 0;

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>line[i].p1.x>>line[i].p1.y>>line[i].p2.x>>line[i].p2.y;
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = i;j<=N;++j)
		{
			if(lineIntersection(line[i],line[j]) && (find(i) != find(j)))
			{
				merge(i,j);
			}
		}
	}

	for(int i = 1;i<=N;++i)
	{
		if(p[i] < 0)
		{
			groupnum++;
			if(abs(p[i]) > maxval)
			{
				maxval = abs(p[i]);
			}
		}
	}

	cout<<groupnum<<"\n"<<maxval;

	return 0;
}


