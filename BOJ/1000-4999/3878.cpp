#include <bits/stdc++.h>

// 3878 점 분리

// update 220613

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 105;

struct Point
{
	long long x,y,px,py;

	bool operator <(Point O)
	{
		if(x != O.x)
		{
			return x < O.x;
		}
		return y < O.y;
	};
	bool operator ==(Point O)
	{
		return y == O.y && x == O.x;
	};
	bool operator <=(Point O)
	{
		if(y == O.y && x == O.x)
		{
			return true;
		}
		if(x != O.x)
		{
			return x <= O.x;
		}
		return y <= O.y;
	};
};

int T;
int N,M;
vector<Point> blackP, whiteP;
vector<int> bCH, wCH;
vector<int> blackV, whiteV;

void swapPoint(Point a, Point b)
{
	Point temp;
	temp = a;
	a = b;
	b = temp;
}

long long ccw(const Point &a, const Point &b, const Point &c)
{
	long long ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	// long long ret = 1ll * (a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
	if(ret > 0)
	{
		return 1;
	}
	else if(ret < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

bool intersect(Point a, Point b, Point c, Point d)
{
	long long lineAB = ccw(a,b,c) * ccw(a,b,d);
	long long lineCD = ccw(c,d,a) * ccw(c,d,b);

	if(lineAB == 0 && lineCD == 0)
	{
		if(b < a) swapPoint(a,b);
		if(d < c) swapPoint(c,d);
		return (c <= b && a <= d);
	}
	return lineAB <= 0 && lineCD <= 0;
}

bool compare(Point a, Point b)
{
	if(a.py * b.px != a.px * b.py)
	{
		return 1LL*a.py*b.px < a.px*b.py;
	}
	if(a.y != b.y)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

void init()
{
	blackP.clear();
	whiteP.clear();
	bCH.clear();
	wCH.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		init();

		bool invalid = false;

		cin>>N>>M;

		for(int i = 1;i<=N;++i)
		{
			long long x,y;
			cin>>x>>y;
			blackP.push_back({x,y,0,0});
		}
		for(int i = 1;i<=M;++i)
		{
			long long x,y;
			cin>>x>>y;
			whiteP.push_back({x,y,0,0});
		}

		if(N == 1 && M == 1)
		{
			cout<<"YES\n";
			continue;
		}
		
		sort(blackP.begin(),blackP.end(), compare);
		sort(whiteP.begin(),whiteP.end(), compare);

		for(int i = 1;i<N;++i)
		{
			blackP[i].px = blackP[i].x - blackP[0].x;
			blackP[i].py = blackP[i].y - blackP[0].y;
		}
		for(int i = 1;i<M;++i)
		{
			whiteP[i].px = whiteP[i].x - whiteP[0].x;
			whiteP[i].py = whiteP[i].y - whiteP[0].y;
		}

		sort(blackP.begin()+1,blackP.end(), compare);
		sort(whiteP.begin()+1,whiteP.end(), compare);

		if(N == 1)
		{
			bCH.push_back(0);
			bCH.push_back(0);
		}
		else
		{
			bCH.push_back(0);
			bCH.push_back(1);
			int next = 2;
			while(next < N)
			{
				while(bCH.size() >= 2)
				{
					int first, second;
					second = bCH.back();
					bCH.pop_back();
					first = bCH.back();

					if(ccw(blackP[first], blackP[second], blackP[next]) > 0)
					{
						bCH.push_back(second);
						break;
					}
				}
				bCH.push_back(next++);
			}
		}

		if(M == 1)
		{
			wCH.push_back(0);
			wCH.push_back(0);
		}
		else
		{
			wCH.push_back(0);
			wCH.push_back(1);
			int next = 2;
			while(next < M)
			{
				while(wCH.size() >= 2)
				{
					int first, second;
					second = wCH.back();
					wCH.pop_back();
					first = wCH.back();

					if(ccw(whiteP[first], whiteP[second], whiteP[next]) > 0)
					{
						wCH.push_back(second);
						break;
					}
				}
				wCH.push_back(next++);
			}
		}

		int bsize = bCH.size();
		int wsize = wCH.size();

		for(int i = 0;i<bsize;++i)
		{
			for(int j = 0;j<wsize;++j)
			{
				Point a,b,c,d;
				a = blackP[bCH[i]];
				b = blackP[bCH[(i+1) % bsize]];
				c = whiteP[wCH[j]];
				d = whiteP[wCH[(j+1) % wsize]];
				if(intersect(a,b,c,d) == true)
				{
					invalid = true;
					break;
				}
			}
			if(invalid)
			{
				break;
			}
		}

		bool BCHincludeWP = true;
		bool WCHincludeBP = true;

		for(int i = 0;i<bsize;++i)
		{
			for(int j = 0;j<wsize;++j)
			{
				Point a,b,c;
				a = blackP[bCH[i]];
				b = blackP[bCH[(i+1) % bsize]];
				c = whiteP[wCH[j]];

				if(ccw(a,b,c) <= 0)
				{
					BCHincludeWP = false;
					break;
				}
			}
			if(!BCHincludeWP)
			{
				break;
			}
		}
		if(BCHincludeWP)
		{
			invalid = true;
		}

		for(int i = 0;i<wsize;++i)
		{
			for(int j = 0;j<bsize;++j)
			{
				Point a,b,c;
				a = whiteP[wCH[i]];
				b = whiteP[wCH[(i+1) % wsize]];
				c = blackP[bCH[j]];

				if(ccw(a,b,c) <= 0)
				{
					WCHincludeBP = false;
					break;
				}
			}
			if(!WCHincludeBP)
			{
				break;
			}
		}
		if(WCHincludeBP)
		{
			invalid = true;
		} 

		if(invalid)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	
	return 0;
}


