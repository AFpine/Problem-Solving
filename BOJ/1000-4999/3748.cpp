#include <bits/stdc++.h>

// 3748 Lucky cities

// update 220516

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int T;
int N,M,cnt = 0;
int bcccnt = 0;
int dfsn[MAX];
vector<pair<int,int>> adj[MAX];
vector<vector<pair<pair<int,int>,int>>> bcc;
stack<pair<pair<int,int>,int>> st;
int dist[MAX];
int bccidx[MAX];
bool LuckyCity[MAX];
int selectedBcc[MAX];
bool oddCycle;
int cntLuckyCity;

void init()
{
	cnt = 0;
	bcccnt = 0;
	cntLuckyCity = 0;
	oddCycle = true;
	bcc.clear();
	while(!st.empty())
	{
		st.pop();
	}
	for(int i = 0;i<MAX;++i)
	{
		selectedBcc[i] = -1;
		LuckyCity[i] = false;
		bccidx[i] = 0;
		dist[i] = 0;
		dfsn[i] = 0;
		adj[i].clear();
	}
}

void bfs(vector<pair<pair<int,int>,int>> &bcc, int idx)
{
	queue<int> Q;
	Q.push(bcc[0].first.first);
	selectedBcc[Q.front()] = idx;
	dist[Q.front()] = 1;

	while(!Q.empty())
	{ 
		int cur = Q.front();
		Q.pop();

		for(auto &e : adj[cur])
		{
			if(bccidx[e.second] == idx && selectedBcc[e.first] != idx)
			{
				selectedBcc[e.first] = idx;
				dist[e.first] = dist[cur] + 1;
				Q.push(e.first);
			}
		}
	}
}

int dfs(int cur, int prev = -1)
{//BCC Algorithm
	int res = dfsn[cur] = ++cnt;
    //res 는 dfs 상에서 트리, 역박향 간선으로 도달 가능한 최소의 dfsn
    //scc 에서도 비슷하게, 이 정점으로 부터 도달할 수 있는 제일 작은 dfsn
	for(auto &e : adj[cur])
	{
		if(e.first == prev)
		{//dfs 트리에서 자신의 부모면 스킵
			continue;
		}
		//아직 방문하지 않은 간선이면 스택에 간선 (cur,e)를 push
		if(dfsn[cur] > dfsn[e.first])
		{//역방향 간선
        	st.push({{cur,e.first},e.second});
		}
		if(dfsn[e.first] > 0)
		{//트리 간선
			res = min(res,dfsn[e.first]);
		}
		else
		{//재귀적으로
			int temp = dfs(e.first,cur);
			res = min(res,temp);
            //e가 dfs트리상에서 cur의 조상 노드로 갈 수 없다면 : 새로운 BCC
			if(temp >= dfsn[cur])
			{//스택에 쌓여있던 간선을 뺀다 / 간선 (cur,e)까지만 뺀다
				vector<pair<pair<int,int>,int>> tempbcc;
				while(!st.empty() && st.top().first != pair<int,int>(cur,e.first))
				{
					bccidx[st.top().second] = bcccnt;
					tempbcc.push_back({st.top().first, st.top().second});
					st.pop();
				}
				tempbcc.push_back({st.top().first, st.top().second});
				bccidx[st.top().second] = bcccnt;
				st.pop();
				bcc.push_back(tempbcc);
				bcccnt++;
			}
		}
	}
	
    //res : 최소 도달 가능 dfsn
	return res;
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

		cin>>N>>M;
		for(int i = 1;i<=M;++i)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back({v,i});
			adj[v].push_back({u,i});
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
			int idx = bccidx[curbcc[0].second];
			oddCycle = false;
			bfs(curbcc,idx);
			for(auto &e : curbcc)
			{
				if(dist[e.first.first] == dist[e.first.second])
				{
					oddCycle = true;
				}
			}
			if(oddCycle)
			{
				for(auto &e : curbcc)
				{
					LuckyCity[e.first.first] = true;
					LuckyCity[e.first.second] = true;
				}
			}
		}

		for(int i = 1;i<=N;++i)
		{
			if(LuckyCity[i] == true)
			{
				cntLuckyCity++;
			}
		}
		cout<<cntLuckyCity<<'\n';

	}

	return 0;
}
