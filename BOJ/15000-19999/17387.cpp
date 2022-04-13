#include <bits/stdc++.h>

// 17383 Line Intersection (Counter Clockwise Algorithm)

// update 220413

using namespace std;

static const int INF = 1e9+1;

struct Point
{
	int x;
	int y;
};

struct Line
{
	Point p1;
	Point p2;
};

bool compare(Point left, Point right)
{//true : right point is greater than left point
	if(left.x == right.x)
	{
		if(left.y <= right.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(left.x < right.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ccw(Point p1, Point p2, Point p3)
{
	long long result = (long long)(p2.x-p1.x)*(long long)(p3.y-p1.y) - (long long)(p3.x-p1.x)*(long long)(p2.y-p1.y);
	if(result > 0)
	{//counter clockwise	
		return 1;
	}
	else if(result < 0)
	{//clockwise
		return -1;
	}
	else
	{//line
		return 0;
	}
}

bool lineintersection(Line l1, Line l2)
{
	int temp1 = ccw(l1.p1, l1.p2, l2.p1)*ccw(l1.p1,l1.p2,l2.p2);
	int temp2 = ccw(l2.p1, l2.p2, l1.p1)*ccw(l2.p1,l2.p2,l1.p2);
	if(temp1 == 0 && temp2 == 0)
	{
		if(compare(l1.p2,l1.p1))
		{
			Point temppoint = l1.p2;
			l1.p2 = l1.p1;
			l1.p1 = temppoint;
		}
		if(compare(l2.p2,l2.p1))
		{
			Point temppoint = l2.p2;
			l2.p2 = l2.p1;
			l2.p1 = temppoint;
		}
		//now p2 is greater than p1

		if(compare(l2.p1,l1.p2) && compare(l1.p1,l2.p2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(temp1 <= 0 && temp2 <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Line line1,line2;

	cin>>line1.p1.x>>line1.p1.y>>line1.p2.x>>line1.p2.y;
	cin>>line2.p1.x>>line2.p1.y>>line2.p2.x>>line2.p2.y;

	if(lineintersection(line1,line2))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}

	return 0;
}