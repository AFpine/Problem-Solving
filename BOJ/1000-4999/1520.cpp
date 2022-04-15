#include <bits/stdc++.h>

// 1520 Downroad (Dynamic programming)

// update 220415

using namespace std;

static const int INF = 1e9+1;

int MAP[501][501];
int dp[501][501];
// if value is -1, not visited
// if value isn't -1, is visited. so we can return dp[i][j] 

int result = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int DFS(int M, int N, pair<int,int> cur)
{
	if(cur.first == M && cur.second == N)
	{
		return 1;
	}
	if(dp[cur.first][cur.second] != -1)
	{
		return dp[cur.first][cur.second];
	}
	dp[cur.first][cur.second] = 0;
	for(int dir = 0;dir<4;++dir)
	{
		int x = cur.first+dx[dir];
		int y = cur.second+dy[dir];

		if(x <= 0 || x > M || y <= 0 || y > N)
		{
			continue;
		}
		if(MAP[cur.first][cur.second] > MAP[x][y])
		{
			dp[cur.first][cur.second] += DFS(M,N,{x,y});
		}
	}
	return dp[cur.first][cur.second];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M,N;
	cin>>M>>N;

	for(int i = 1;i<=M;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			cin>>MAP[i][j];
			dp[i][j] = -1;
		}
	}

	cout<<DFS(M,N,{1,1});

	return 0;
}