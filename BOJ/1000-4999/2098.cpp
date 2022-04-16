#include <bits/stdc++.h>

// 2098 Traveling Salesman Problem (TSP, Bit masking, DP)

// update 220416

using namespace std;

static const int INF = 1e9+1;

int N;
int W[17][17];	//weight from i to j
//if weight is 0, the edge isn't exist

int dp[17][1<<17];

int TSP(int current, int visited)
{//current is current vertex, visited is bitfield contains visited vertexs
	
	int returnvalue = dp[current][visited];
	
	if(returnvalue != 0)
	{//만약 이전의 TSP에서 current 에 도달 했었다면, 그리고 그 때 visited한 정점들이 같다면
	// 이전에 구했던 값을 다시 return 하면 됨 (동적 계획법) (유효한 경로라면 어떤 값 일것이고, 유효한 경로가 아니면 INF일 것)
		return returnvalue;
	}
	
	if(visited == (1<<N+1)-1)
	{//containing current vertex, all vertexs are visited
		if(W[current][1] != INF)
		{//모든 정점을 거치고 다시 처음(vertex 1)으로 돌아가는데 걸리는 가중치를 return
			return W[current][1];
		}
		else
		{//처음으로 돌아가는 길이 없으면 갈 수 없으므로 INF return
			return INF;
		}
	}

	returnvalue = INF;
	for(int i = 1;i<=N;++i)
	{
		if(W[current][i] != INF && !(visited&(1<<i)))
		{//current에서 i로 이동할 수 있고(간선이 존재하고), i에 들른 적이 없다면
			returnvalue = min(returnvalue, TSP(i, visited|(1<<i)) + W[current][i]);
		}
	}

	//current에서 아무 곳도 이동할 수 없다면(길이 없다면) dp[current][visited] 는 INF이다
	dp[current][visited] = returnvalue;

	return dp[current][visited];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			cin>>W[i][j];
			if(W[i][j] == 0)
			{
				W[i][j] = INF;
			}
		}
	}
	
	cout<<TSP(1,3);

	return 0;
}