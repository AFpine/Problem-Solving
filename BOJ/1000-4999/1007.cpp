#include <bits/stdc++.h>

// 1007 벡터 매칭

// update 220616

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2005;

struct Point
{
	double x,y;
};

int T;
int N;
Point p[21];
bool plusVector[21];
double result = INF;

double vectorLength(double a, double b)
{
	return sqrt(a*a + b*b);
}

void dfs(int n, int idx, pair<double,double> pair)
{
	if(n == N/2)
	{
		result = min(result,vectorLength(pair.first, pair.second));
		return;
	}
	else
	{
		for(int i = idx;i<=N;++i)
		{
			if(plusVector[i] == false)
			{
				plusVector[i] = true;
				dfs(n+1, i, {pair.first+(p[i].x)*2, pair.second+(p[i].y)*2});
				plusVector[i] = false;
			}
		}
	}
}

void init()
{
	fill(plusVector,plusVector+21,false);
	result = INF;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(12);

	cin>>T;
	while(T--)
	{
		init();

		cin>>N;

		pair<double,double> temp = {0,0};

		for(int i = 1;i<=N;++i)
		{
			cin>>p[i].x>>p[i].y;
			temp.first -= p[i].x;
			temp.second -= p[i].y;
		}

		dfs(0,1,temp);

		cout<<result<<'\n';
	}

	return 0;
}