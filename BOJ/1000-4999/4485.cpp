#include <bits/stdc++.h>

// 4485 녹색 옷 입은 애가 젤다지?

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
int cave[126][126];
int dist[126][126];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(queue<pair<int,int>> &Q)
{
	while(!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();

		for(int dir = 0;dir<4;++dir)
		{
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if(x < 1 || x > N || y < 1 || y > N)
			{
				continue;
			}
			if(dist[x][y] > dist[cur.first][cur.second] + cave[x][y])
			{
				dist[x][y] = dist[cur.first][cur.second] + cave[x][y];
				Q.push({x,y});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 1;
	
	while(true)
	{
		cin>>N;

		if(N == 0)
		{
			break;
		}
		
		memset(dist,INF,sizeof(dist));
		
		queue<pair<int,int>> Q;

		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=N;++j)
			{
				cin>>cave[i][j];
			}
		}
		
		Q.push({1,1});
		dist[1][1] = cave[1][1];

		bfs(Q);

		cout<<"Problem "<<tc<<": "<<dist[N][N]<<'\n';
		tc++;
	}


	return 0;
}

