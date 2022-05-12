#include <bits/stdc++.h>

// 2150 Strongly Connected Component

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10001;

int V,E;
int A,B;
int dfsnum = 0;
int dfsn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> st;
vector<vector<int>> scc;

int dfs(int cur)
{
	dfsn[cur] = ++dfsnum;
	st.push(cur);

	int res = dfsn[cur];
	for(auto &e : adj[cur])
	{
		if(dfsn[e] == 0)
		{
			res = min(res,dfs(e));
		}
		else if(finished[e] == false)
		{	
			res = min(res,dfsn[e]);
		}
	}

	if(res == dfsn[cur])
	{
		vector<int> tempscc;
		
		while(true)
		{
			int a = st.top();
			st.pop();
			tempscc.push_back(a);
			finished[a] = true;
			if(a == cur)
			{
				break;
			}
		}
		sort(tempscc.begin(),tempscc.end());
		scc.push_back(tempscc);
	}
	return res;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>V>>E;

	for(int i = 1;i<=E;++i)
	{
		cin>>A>>B;
		adj[A].push_back(B);
	}

	for(int i = 1;i<=V;++i)
	{
		if(dfsn[i] == 0)
		{
			dfs(i);
		}
	}

	sort(scc.begin(),scc.end());

	cout<<scc.size()<<"\n";

	for(auto &s : scc)
	{
		for(auto x : s)
		{
			cout<<x<<" ";
		}
		cout<<"-1\n";
	}

	return 0;
}
