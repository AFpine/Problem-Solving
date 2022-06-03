#include <bits/stdc++.h>

// 13166 범죄 파티

// update 220602

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 400005;

int N;
int B[MAX],level[MAX];
bool used[MAX];
vector<pair<int,int>> adj[MAX];

void bfs(int k)
{
	fill(level,level+MAX,-1);
	queue<int> Q;

	for(int i = 1;i<=N;++i)
	{
		if(used[i] == false)
		{
			level[i] = 0;
			Q.push(i);
		}
	}

	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for(auto &b : adj[a])
		{
			if((k >= b.second) && (B[b.first] != -1 && level[B[b.first]] == -1))
			{
				level[B[b.first]] = level[a] + 1;
				Q.push(B[b.first]);
			}
		}
	}
}

bool dfs(int a, int k)
{
	for(auto &b : adj[a])
	{
		if((k >= b.second) && (B[b.first] == -1) || (level[B[b.first]] == level[a] + 1 && dfs(B[b.first],k) == true))
		{
			used[a] = true;
			B[b.first] = a;
			return true;
		}
	}
	return false;
}

bool solve(int k)
{
	fill(B,B+MAX,-1);
	fill(used,used+MAX,false);
	int totalMatch = 0;
	while(true)
	{
		bfs(k);

		int flow = 0;
		for(int i = 1;i<=N;++i)
		{
			if(used[i] == false && dfs(i,k) == true)
			{
				flow++;
			}
		}
		if(flow == 0)
		{
			break;
		}
		totalMatch += flow;
	}

	if(totalMatch >= N)
	{
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		adj[i].push_back({a,b});
		adj[i].push_back({c,d});
	}

	int result = 0;
	int l = 0, r = 1000005;
	bool able = false;
	while(l < r)
	{
		int mid = (l+r)/2;
		if(solve(mid))
		{
			able = true;
			result = mid;
			r = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	if(able)
	{
		cout<<result;
	}
	else
	{
		cout<<"-1";
	}

	return 0;
}

