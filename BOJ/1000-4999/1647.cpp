#include <bits/stdc++.h>

// 1647 City separation plan (Prim algorithm)

// update 220327

using namespace std;

struct House
{
	vector<pair<int,int>> Road;
};

struct compare
{
	bool operator()(pair<int,int>& a, pair<int,int>& b)
	{
		return a.second > b.second;
	}
};

House city[100001];
bool visited[100001];

int totalweight = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	int A,B,C;
	int separateroad = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
	pair<int,int> now;

	cin>>N>>M;

	for(int i = 0;i<M;++i)
	{
		cin>>A>>B>>C;
		city[A].Road.push_back({B,C});
		city[B].Road.push_back({A,C});
	}	
	
	visited[1] = true;
	for(auto x : city[1].Road)
	{
		pq.push(x);
	}

	for(int i = 1;i<=N-1;++i)
	{//Prim algorithm
		while(!pq.empty())
		{
			now = pq.top();
			pq.pop();
			if(visited[now.first] == false)
			{
				visited[now.first] = true;
				if(separateroad < now.second)
				{
					separateroad = now.second;
				}
				totalweight += now.second;
				break;
			}
		}
		for(auto x : city[now.first].Road)
		{
			if(visited[x.first] == false)
			{
				pq.push(x);
			}
		}
	}

	cout<<totalweight - separateroad<<'\n';

	return 0;	
}