#include <bits/stdc++.h>

// Hide and Seek 3 (Dijkstra / 0-1 BFS)

// update 220310

using namespace std;

bool check[100001];
int dist[100001];

struct compare
{
	bool operator()(int a, int b)
	{
		return dist[a]>dist[b];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,K;
	int now;
	//queue<int> q;
	priority_queue<int,vector<int>, compare>q;
	cin>>N>>K;
	for(int i = 0;i<=100000;++i)
	{
		check[i] = false;
		dist[i] = 100000000;
	}
	dist[N] = 0;
	q.push(N);

	while(!q.empty())
	{
		now = q.top();
		q.pop();
		if(check[now] == true)
		{
			continue;
		}
		check[now] = true;
		if(now == K)
		{
			break;
		}
		if(now*2 <= 100000 && check[now*2] == false)
		{
			if(dist[now*2] > dist[now])
			{
				dist[now*2] = dist[now];
				q.push(now*2);
			}
		}
		if(now+1 <= 100000 && check[now+1] == false)
		{
			if(dist[now+1] > dist[now] + 1)
			{
				dist[now+1] = dist[now] + 1;
				q.push(now+1);
			}
		}
		if(now-1 >= 0 && check[now-1] == false)
		{
			if(dist[now-1] > dist[now] + 1)
			{
				dist[now-1] = dist[now] + 1;
				q.push(now-1);
			}
		}
	}
	cout<<dist[K]<<"\n";

	
}
