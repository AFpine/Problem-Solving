#include <bits/stdc++.h>

// 3665 최종 순위

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

int T;
int n,m;
int a,b;
int scoreofTeam[501];
int teamofScore[501];
bool adj[501][501];
int indegree[501];
int result[501];
bool impossible,indirect;

void init()
{
	impossible = false;
	indirect = false;
	for(int i = 1;i<=500;++i)
	{
		scoreofTeam[i] = 0;
		teamofScore[i] = 0;
		indegree[i] = 0;
		result[i] = 0;
		for(int j = 1;j<=500;++j)
		{
			adj[i][j] = false;
		}
	}
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
		
		queue<int> Q;

		cin>>n;
		for(int i = 1;i<=n;++i)
		{
			int team;
			cin>>team;
			scoreofTeam[team] = i;
			teamofScore[i] = team;
		}
		for(int i = 1;i<n;++i)
		{
			for(int j = i+1;j<=n;++j)
			{
				adj[teamofScore[i]][teamofScore[j]] = true;
				indegree[teamofScore[j]]++;
			}
		}
		cin>>m;
		for(int i = 1;i<=m;++i)
		{
			cin>>a>>b;
			if(scoreofTeam[a] < scoreofTeam[b])
			{
				adj[b][a] = true;
				adj[a][b] = false;
				indegree[a]++;
				indegree[b]--;
			}
			else
			{
				adj[a][b] = true;
				adj[b][a] = false;
				indegree[b]++;
				indegree[a]--;
			}
		}

		for(int i = 1;i<=n;++i)
		{
			if(indegree[i] == 0)
			{
				Q.push(i);
			}
		}

		for(int i = 1;i<=n;++i)
		{
			if(Q.empty())
			{
				impossible = true;
				break;
			}
			int cur = Q.front();
			Q.pop();
			if(!Q.empty())
			{
				indirect = true;
				break;
			}
			result[i] = cur;
			for(int j = 1;j<=n;++j)
			{
				if(adj[cur][j] == true)
				{
					if(--indegree[j] == 0)
					{
						Q.push(j);
					}
				}
			}
		}

		if(impossible)
		{
			cout<<"IMPOSSIBLE";
		}
		else if(indirect)
		{
			cout<<"?";
		}
		else
		{
			for(int i = 1;i<=n;++i)
			{
				cout<<result[i]<<" ";
			}
		}
		cout<<'\n';
	}

	return 0;
}
