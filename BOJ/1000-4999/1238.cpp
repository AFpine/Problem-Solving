#include <bits/stdc++.h>

using namespace std;

// 1238 Party (Dijkstra)

// update 220317

static const int INF = 100000000;

int road[1001][1001];
int tox[1001];
int tohome[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,X;
	int a,b,c;
	int maxvalue=0;
	priority_queue<int,vector<int>,greater<int>>q;

	cin>>N>>M>>X;

	for(int i = 1;i<=N;++i)		//init
	{
		tox[i] = INF;
		tohome[i] = INF;
		for(int j = 1;j<=N;++j)
		{
			road[i][j] = INF;
		}
	}

	for(int i = 0;i<M;++i)
	{
		cin>>a>>b>>c;
		road[a][b] = c;
	}

	tox[X] = 0;
	q.push(X);

	while(!q.empty())
	{
		int now = q.top();
		q.pop();
		

		for(int i = 1;i<=N;++i)
		{
			if(road[i][now] < INF && tox[i] > tox[now] + road[i][now])
			{
				tox[i] = tox[now] + road[i][now];
				q.push(i);
			}
		}
	}
	tohome[X] = 0;
	q.push(X);

	while(!q.empty())
	{
		int now = q.top();
		q.pop();
		

		for(int i = 1;i<=N;++i)
		{
			if(road[now][i] < INF && tohome[i] > tohome[now] + road[now][i])
			{
				tohome[i] = tohome[now] + road[now][i];
				q.push(i);
			}
		}
	}

	for(int i = 1;i<=N;++i)
	{
		if(maxvalue < tox[i] + tohome[i])
		{
			maxvalue = tox[i] + tohome[i];
		}
	}

	cout<<maxvalue<<"\n";

}
