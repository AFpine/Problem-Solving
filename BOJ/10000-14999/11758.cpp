#include <bits/stdc++.h>

// 11758 CCW

// update 220426

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

struct Point
{
    int x,y;
};


int cross(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    Point p1,p2,p3;

    cin>>p1.x>>p1.y;
    cin>>p2.x>>p2.y;
    cin>>p3.x>>p3.y;

    int c = cross(p1,p2,p3);

    if(c > 0)
    {
        cout<<"1";
    }
    else if(c < 0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<"0";
    }

	return 0;
}

