#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <limits>
#include <cstdint>

// 1916 Dijkstra

using namespace std;

static int INF = 987654321;

struct compare
{
	bool operator()(pair<int,int> a, pair<int,int> b) const
	{
		return a.second > b.second;
	}

};


vector<pair<int,int>> arr[1001];
int dist[1001];
bool visited [1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
   	int N,M;
	int n1,n2,w;
	int start, end;

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		dist[i] = INF;
		visited[i] =false;
	}

	for(int i = 0;i<M;++i)
	{
		cin>>n1>>n2>>w;
		arr[n1].push_back(pair<int,int>(n2,w));		//first is destination, second is path
	}
    cin>>start>>end;
	
	dist[start] = 0;

	pq.push({start,dist[start]});					//first is now, second is dist of now;

	while(!pq.empty())
	{
		int now = pq.top().first;					
		int distance = pq.top().second;
		pq.pop();
		if(visited[now] == true)
		{
			continue;
		}
		visited[now] = true;
		for(int i = 0;i<arr[now].size();++i)
		{
			if(visited[arr[now][i].first] == false && distance + arr[now][i].second < dist[arr[now][i].first])
			{
				dist[arr[now][i].first] = distance + arr[now][i].second;
				pq.push(pair<int,int>(arr[now][i].first, dist[arr[now][i].first]));
			}
		}
	}

	cout<<dist[end]<<"\n";

}
