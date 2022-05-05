#include <bits/stdc++.h>

// 1194 달이 차오른다, 가자.

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int BMAX = 7;

int N,M;
char maze[51][51];
int dist[51][51];
bool visited[51][51][1<<BMAX];

queue<pair<int,int>> Q;
queue<int> keyQ;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> bfs()
{
	while(!Q.empty())
	{
		pair<int,int>cur = Q.front();
		int curkey = keyQ.front();
		Q.pop();
		keyQ.pop();

		for(int dir = 0;dir<4;++dir)
		{
			int x = cur.first+dx[dir];
			int y = cur.second+dy[dir];

			if(x < 1 || x > N || y < 1 || y > M)
			{
				continue;
			}
			if(maze[x][y] == '#')
			{
				continue;
			}
			if(visited[x][y][curkey] == true)
			{
				continue;
			}
			if(maze[x][y] == '1')
			{
				dist[x][y] = dist[cur.first][cur.second] + 1;
				return pair<int,int>(x,y);
			}
			if(maze[x][y] == '.' || maze[x][y] == '0')
			{
				visited[x][y][curkey] = true;
				dist[x][y] = dist[cur.first][cur.second] + 1;
				Q.push({x,y});
				keyQ.push(curkey);
			}
			if((maze[x][y] >= 'a') && (maze[x][y] <= 'f'))
			{
				if((curkey & (1<<(maze[x][y]-'a'))) == 0)
				{
					visited[x][y][curkey] = true;
					dist[x][y] = dist[cur.first][cur.second] + 1;
					Q.push({x,y});
					keyQ.push((curkey|(1<<(maze[x][y]-'a'))));
				}
				else
				{
					visited[x][y][curkey] = true;
					dist[x][y] = dist[cur.first][cur.second] + 1;
					Q.push({x,y});
					keyQ.push(curkey);
				}
			}
			if((maze[x][y] >= 'A') && (maze[x][y] <= 'F') && ((curkey & (1<<(maze[x][y]-'A'))) != 0))
			{
				visited[x][y][curkey] = true;
				dist[x][y] = dist[cur.first][cur.second] + 1;
				Q.push({x,y});
				keyQ.push(curkey);
			}
		}
	}
	return pair<int,int>(0,0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dist,INF,sizeof(dist));

	cin>>N>>M;
	string s;
	pair<int,int> result;

	for(int i = 1;i<=N;++i)
	{
		cin>>s;
		for(int j = 1;j<=M;++j)
		{
			maze[i][j] = s[j-1];
			if(maze[i][j] == '0')
			{
				Q.push({i,j});
				keyQ.push(0);
				dist[i][j] = 0;
				visited[i][j][0] = true;
			}
		}
	}

	result = bfs();

	if(result == pair<int,int>(0,0))
	{
		cout<<"-1";
	}
	else
	{
		cout<<dist[result.first][result.second];
	}

	return 0;
}

