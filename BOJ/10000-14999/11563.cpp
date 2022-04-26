#include <bits/stdc++.h>

// 11563 연돌이와 고잠녀 (Geometry)

// update 220426

using namespace std;

const int INF = 1e9+7;
const double dINF = 2e9+5;
const int minINF = -2e9-1;

struct Point
{
    double x,y;
};

struct Line
{
    Point p1,p2;
};

int n,m;

Line sc[2001];
Line an[2001];
double probresult = -1;

double dotdist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

double crossproduct(double x1, double y1, double x2, double y2)
{
    return x1*y2 - x2*y1;
}

double dotproduct(double x1, double y1, double x2, double y2)
{
    return x1*x2 + y1*y2;
}

double dotline(Point p, Line l)
{
    double d1,d2;
    d1 = dotproduct(l.p1.x-l.p2.x, l.p1.y-l.p2.y, p.x-l.p2.x, p.y-l.p2.y);
    d2 = dotproduct(l.p2.x-l.p1.x, l.p2.y-l.p1.y, p.x-l.p1.x, p.y-l.p1.y);
    if(d1 * d2 >= 0)
    {
        return abs(crossproduct(l.p2.x-l.p1.x, l.p2.y-l.p1.y, p.x-l.p1.x, p.y-l.p1.y)) / dotdist(l.p1.x,l.p1.y, l.p2.x, l.p2.y);
    }
    else
    {
        return -1;
    }
}

double shortestpath(Line l1, Line l2)
{//l1 is sinchon, l2 is anam
    double result = dINF;
    double temp;

    result = min(result, dotdist(l1.p1.x, l1.p1.y, l2.p1.x, l2.p1.y));
    result = min(result, dotdist(l1.p1.x, l1.p1.y, l2.p2.x, l2.p2.y));
    result = min(result, dotdist(l1.p2.x, l1.p2.y, l2.p1.x, l2.p1.y));
    result = min(result, dotdist(l1.p2.x, l1.p2.y, l2.p2.x, l2.p2.y));

    temp = dotline(l1.p1,l2);
    if(temp >= 0)
    {
        result = min(result,dotline(l1.p1,l2));
    }
    temp = dotline(l1.p2,l2);
    if(temp >= 0)
    {
        result = min(result,dotline(l1.p2,l2));
    }
    temp = dotline(l2.p1,l1);
    if(temp >= 0)
    {
        result = min(result,dotline(l2.p1,l1));
    }
    temp = dotline(l2.p2,l1);
    if(temp >= 0)
    {
        result = min(result,dotline(l2.p2,l1));
    }
    
    return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;

    for(int i = 1;i<=n;++i)
    {
        cin>>sc[i].p1.x>>sc[i].p1.y>>sc[i].p2.x>>sc[i].p2.y;
    }

    for(int i = 1;i<=m;++i)
    {
        cin>>an[i].p1.x>>an[i].p1.y>>an[i].p2.x>>an[i].p2.y;
    }

    for(int i = 1;i<=n;++i)
    {
        for(int j = 1;j<=m;++j)
        {
            if(probresult < 0)
            {
                probresult = shortestpath(sc[i],an[j]);
            }
            else
            {
                probresult = min(probresult,shortestpath(sc[i],an[j]));
            }
        }
    }
    
    cout.precision(16);
    cout<<probresult;

	return 0;
}

