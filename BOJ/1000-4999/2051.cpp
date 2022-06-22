#include <bits/stdc++.h>

// 2051 최소 버텍스 커버

// update 220622

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const long long MOD = 1e9+7;

int N,M;
int A[MAX], B[MAX];
bool mvcA[MAX], mvcB[MAX];
bool visited[MAX];
vector<int> adj[MAX];
vector<int> reverseadj[MAX];

bool dfs(int a)
{
	if(visited[a])
	{
		return false;
	}
	visited[a] = true;
	for(auto &b : adj[a])
	{
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void bfs(int cur)
{
	queue<int> Q;

	visited[cur] = true;
	Q.push(cur);

	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		mvcA[a] = false;

		for(auto &b : adj[a])
		{
			if(visited[B[b]])
			{//사용된 a는 continue
				continue;
			}
			if(A[a] != b && B[b] != -1)
			{//매칭에 사용된 간선을 사용하지 않고 선택된 b
				Q.push(B[b]);
				visited[B[b]] = true;
				mvcB[b] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		int temp;
		cin>>temp;
		for(int j = 1;j<=temp;++j)
		{
			int t;
			cin>>t;
			adj[i].push_back(t);
			reverseadj[t].push_back(i);
		}
	}
	
	fill(A,A+MAX,-1);
	fill(B,B+MAX,-1);
	fill(visited,visited+MAX,false);

	int match = 0;
	for(int i = 1;i<=N;++i)
	{
		if(A[i] == -1)
		{
			fill(visited,visited+MAX,false);
			if(dfs(i))
			{
				match++;
			}
		}
	}
	cout<<match<<'\n';
	
	fill(mvcA,mvcA+MAX,true);
	fill(mvcB,mvcB+MAX,false);
	fill(visited,visited+MAX,false);

	for(int i = 1;i<=N;++i)
	{
		if(A[i] == -1 && !visited[i])
		{
			bfs(i);
		}
	}

	int cntA = 0, cntB = 0;
	for(int i = 1;i<=N;++i)
	{
		if(mvcA[i])
		{
			cntA++;
		}
	}
	for(int i = 1;i<=M;++i)
	{
		if(mvcB[i])
		{
			cntB++;
		}
	}


	cout<<cntA<<" ";
	for(int i = 1;i<=N;++i)
	{
		if(mvcA[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<"\n";
	
	cout<<cntB<<" ";
	for(int i = 1;i<=M;++i)
	{
		if(mvcB[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';

	
	return 0;
}