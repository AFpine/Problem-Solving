#include <bits/stdc++.h>

// 1261 알고스팟

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M;
char maze[101][101];
int dist[101][101];
string s;
queue<pair<int,int>> Q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs()
{
	while(!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();

		for(int dir = 0;dir<4;++dir)
		{
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if(x < 1 || x > N || y < 1 || y > M)
			{
				continue;
			}
			if(maze[x][y] == '1')
			{
				if(dist[x][y] > dist[cur.first][cur.second] + 1)
				{
					dist[x][y] = dist[cur.first][cur.second] + 1;
					Q.push({x,y});
				}
			}
			else
			{
				if(dist[x][y] > dist[cur.first][cur.second])
				{
					dist[x][y] = dist[cur.first][cur.second];
					Q.push({x,y});
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dist,INF,sizeof(dist));

	cin>>M>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>s;
		for(int j = 1;j<=M;++j)
		{
			maze[i][j] = s[j-1];
		}
	}
	
	Q.push({1,1});
	dist[1][1] = 0;

	bfs();

	cout<<dist[N][M];

	return 0;
}

