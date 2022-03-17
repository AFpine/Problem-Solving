#include <bits/stdc++.h>

using namespace std;

// 11779 Minimum cost 2 (Dijkstra)
// **A에서 B까지 꼭 하나의 버스만 다니지는 않는다

// update 220317

static const int INF = 1000000001;

int pre[1001];
int bus[1001][1001];
long long dist[1001];

struct compare
{
	bool operator()(int a, int b)
	{
		return dist[a] > dist[b];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	int a,b,c;
	int start, dest;
	int citycnt = 0;
	stack<int> citystack;
	priority_queue<int,vector<int>,compare>q;

	cin>>n>>m;

	for(int i = 1;i<=n;++i)
	{
		pre[i] = - 1;
		dist[i] = INF;
		for(int j = 1;j<=n;++j)
		{
			bus[i][j] = INF;
		}
	}


	for(int i = 0;i<m;++i)
	{
		cin>>a>>b>>c;
		if(bus[a][b] > c)
		{//a부터 b까지 경로에 버스가 하나가 아니므로 그 중에서 가장 비용이 적은 버스를 선택한다
			bus[a][b] = c;
		}
	}
	
	cin>>start>>dest;

	dist[start] = 0;
	pre[start] = -1;
	q.push(start);

	while(!q.empty())
	{
		int now = q.top();
		q.pop();

		for(int i = 1;i<=n;++i)
		{
			if(dist[i] > dist[now] + bus[now][i])
			{
				dist[i] = dist[now] + bus[now][i];
				pre[i] = now;
				q.push(i);
			}
		}
	}

	cout<<dist[dest]<<"\n";

	citystack.push(dest);
	citycnt++;

	while(pre[dest] != -1)
	{
		citystack.push(pre[dest]);
		citycnt++;
		dest = pre[dest];
	}

	cout<<citycnt<<"\n";

	while(!citystack.empty())
	{
		cout<<citystack.top()<<" ";
		citystack.pop();
	}


}
