#include <bits/stdc++.h>

// 10473 인간 대포

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

struct Point
{
	double x,y;
};

int N;
Point start;
Point canon[102];
bool visited[102];
double dist[102];
//0 is dest

double distance(Point& p1, Point& p2)
{
	return sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2));
}

struct compare
{
	bool operator()(int a, int b)
	{
		return dist[a] > dist[b];
	}
};

priority_queue<int,vector<int>,compare> pq;

void dijkstra()
{
	while(!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		// if(visited[cur] == true)
		// {
		// 	continue;
		// }
		visited[cur] = true;
		for(int i = 0;i<=N;++i)
		{
			// if(visited[i] == true)
			// {
			// 	continue;
			// }
			double mincost = min(abs(50-distance(canon[cur],canon[i]))/5.0 + 2, distance(canon[cur],canon[i])/5.0);
			if(dist[i] > dist[cur] + mincost)
			{
				dist[i] = dist[cur] + mincost;
				pq.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<=100;++i)
	{
		dist[i] = 1e+9;
	}

	cin>>start.x>>start.y;
	cin>>canon[0].x>>canon[0].y;

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>canon[i].x>>canon[i].y;
	}
	
	for(int i = 0;i<=N;++i)
	{
		dist[i] = distance(start,canon[i])/5.0;
		pq.push(i);
	}

	dijkstra();

	cout.precision(8);
	cout<<dist[0];

	return 0;
}

