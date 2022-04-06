#include <bits/stdc++.h>

// 1197 Mininum Spanning Tree (Prim Algorithm)

// update 220327

using namespace std;

struct Vertex
{
	int dist;
	vector<pair<int,int>> Edge;
};

struct compare
{
	bool operator()(pair<int,int>& a, pair<int,int>& b)
	{
		return a.second > b.second;
	}
};

Vertex graph[10001];
bool checked[10001];

int totalweight = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V,E;
	int a,b,c;
	pair<int,int> now;
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

	cin>>V>>E;

	for(int i = 0;i<E;++i)
	{
		cin>>a>>b>>c;
		graph[a].Edge.push_back({b,c});
		graph[b].Edge.push_back({a,c});
	}

	checked[1] = true;
	for(auto x : graph[1].Edge)
	{
		pq.push(x);
	}

	for(int i = 1;i<=V-1;++i)
	{
		while(!pq.empty())
		{
			now = pq.top();
			pq.pop();
			if(checked[now.first] == false)
			{
				checked[now.first] = true;
				totalweight += now.second;
				break;
			}
		}
		for(auto x : graph[now.first].Edge)
		{
			pq.push(x);
		}
	}

	cout<<totalweight<<"\n";

	return 0;	
}