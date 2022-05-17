#include <bits/stdc++.h>

// 10891 Cactus? Not cactus?

// update 220517

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 200005;

int N,M;
int x,y;
int cnt = 0;
int dfsn[MAX];
vector<int> adj[MAX];
vector<vector<pair<int,int>>> bcc;
stack<pair<int,int>> st;
int cactusVer[MAX];
bool notCactus = false;

int dfs(int cur, int prev = -1)
{
	int res = dfsn[cur] = ++cnt;
	
	for(auto &next : adj[cur])
	{
		if(next == prev)
		{
			continue;
		}
		if(dfsn[cur] > dfsn[next])
		{
			st.push({cur,next});
		}
		if(dfsn[next] > 0)
		{
			res = min(res,dfsn[next]);
		}
		else
		{
			int temp = dfs(next,cur);
			res = min(res,temp);
			if(temp >= dfsn[cur])
			{
				vector<pair<int,int>> tempbcc;
				while(!st.empty() && st.top() != pair<int,int>(cur,next))
				{
					tempbcc.push_back(st.top());
					st.pop();
				}
				tempbcc.push_back(st.top());
				st.pop();
				bcc.push_back(tempbcc);
			}
		}
	}

	return res;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 1;i<=N;++i)
	{
		if(dfsn[i] == 0)
		{
			dfs(i);
		}
	}

	for(auto &curbcc : bcc)
	{
		set<int> S;

		if(curbcc.size() == 1)
		{
			continue;
		}
		for(auto &e : curbcc)
		{
			S.insert(e.first);
			S.insert(e.second);
		}
		if(S.size() == curbcc.size())
		{
			for(auto &i : S)
			{
				cactusVer[i]++;
			}
		}
		else
		{
			notCactus = true;
		}
	}

	for(int i = 1;i<=N;++i)
	{
		if(cactusVer[i] >= 2)
		{
			notCactus = true;
		}
	}

	if(notCactus == false)
	{
		cout<<"Cactus";
	}
	else
	{
		cout<<"Not cactus";
	}
	
	return 0;
}
