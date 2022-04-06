#include <bits/stdc++.h>

// 2206 Break wall and move (BFS)

// update 220314

using namespace std;

static const int MAX_SIZE = 1000000000;

char mat[1001][1001];
int dist[2][1001][1001];
bool visited[2][1001][1001];

void BFS(int s, int e, bool status, int N, int M)
{
	int i,j;
	queue<pair<int,int>> q;
	queue<bool> breakq;		//true : break wall
							//false : not break
	bool breakwall;
	q.push({s,e});
	breakq.push(status);

	while(!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		breakwall = breakq.front();
		q.pop();
		breakq.pop();

		if(breakwall)
		{
			if(i>1 && dist[1][i-1][j] > dist[1][i][j] + 1)
			{
				if(mat[i-1][j] == '0' && visited[1][i-1][j] == false)
				{
					visited[1][i-1][j] = true;
					dist[1][i-1][j] = dist[1][i][j] + 1;
					q.push({i-1,j});
					breakq.push(true);
				}
			}
			if(i<N && dist[1][i+1][j] > dist[1][i][j] + 1)
			{
				if(mat[i+1][j] == '0' && visited[1][i+1][j] == false)
				{
					visited[1][i+1][j] = true;
					dist[1][i+1][j] = dist[1][i][j] + 1;
					q.push({i+1,j});
					breakq.push(true);
				}
			}
			if(j>1 && dist[1][i][j-1] > dist[1][i][j] + 1)
			{
				if(mat[i][j-1] == '0' && visited[1][i][j-1] == false)
				{
					visited[1][i][j-1] = true;
					dist[1][i][j-1] = dist[1][i][j] + 1;
					q.push({i,j-1});
					breakq.push(true);
				}
			}
			if(j<M && dist[1][i][j+1] > dist[1][i][j] + 1)
			{
				if(mat[i][j+1] == '0' && visited[1][i][j+1] == false)
				{
					visited[1][i][j+1] = true;
					dist[1][i][j+1] = dist[1][i][j] + 1;
					q.push({i,j+1});
					breakq.push(true);
				}
			}
		}
		else
		{
			if(i>1)
			{
				if(mat[i-1][j] == '0' && visited[0][i-1][j] == false && dist[0][i-1][j] > dist[0][i][j] + 1)
				{
					visited[0][i-1][j] = true;
					dist[0][i-1][j] = dist[0][i][j] + 1;
					q.push({i-1,j});
					breakq.push(false);
				}
				else if(mat[i-1][j] == '1' && visited[1][i-1][j] == false && dist[1][i-1][j] > dist[0][i][j] + 1)
				{
					visited[1][i-1][j] = true;
					dist[1][i-1][j] = dist[0][i][j] + 1;
					q.push({i-1,j});
					breakq.push(true);
				}
			}
			if(i<N)
			{
				if(mat[i+1][j] == '0' && visited[0][i+1][j] == false && dist[0][i+1][j] > dist[0][i][j] + 1)
				{
					visited[0][i+1][j] = true;
					dist[0][i+1][j] = dist[0][i][j] + 1;
					q.push({i+1,j});
					breakq.push(false);
				}
				else if(mat[i+1][j] == '1' && visited[1][i+1][j] == false && dist[1][i+1][j] > dist[0][i][j] + 1)
				{
					visited[1][i+1][j] = true;
					dist[1][i+1][j] = dist[0][i][j] + 1;
					q.push({i+1,j});
					breakq.push(true);
				}
			}
			if(j>1)
			{
				if(mat[i][j-1] == '0' && visited[0][i][j-1] == false && dist[0][i][j-1] > dist[0][i][j] + 1)
				{
					visited[0][i][j-1] = true;
					dist[0][i][j-1] = dist[0][i][j] + 1;
					q.push({i,j-1});
					breakq.push(false);
				}
				else if(mat[i][j-1] == '1' && visited[1][i][j-1] == false && dist[1][i][j-1] > dist[0][i][j] + 1)
				{
					visited[1][i][j-1] = true;
					dist[1][i][j-1] = dist[0][i][j] + 1;
					q.push({i,j-1});
					breakq.push(true);
				}
			}
			if(j<M)
			{
				if(mat[i][j+1] == '0' && visited[0][i][j+1] == false && dist[0][i][j+1] > dist[0][i][j] + 1)
				{
					visited[0][i][j+1] = true;
					dist[0][i][j+1] = dist[0][i][j] + 1;
					q.push({i,j+1});
					breakq.push(false);
				}
				else if(mat[i][j+1] == '1' && visited[1][i][j+1] == false && dist[1][i][j+1] > dist[0][i][j] + 1)
				{
					visited[1][i][j+1] = true;
					dist[1][i][j+1] = dist[0][i][j] + 1;
					q.push({i,j+1});
					breakq.push(true);
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

	int N,M;
	string s;
	int result = MAX_SIZE;
	
	cin>>N>>M;

	for(int i = 0;i<N;++i)
	{
		cin>>s;
		for(int j = 0;j<M;++j)
		{
			mat[i+1][j+1] = s[j];
		}
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=M;++j)
		{
			visited[0][i][j] = false;
			visited[1][i][j] = false;
			dist[0][i][j] = MAX_SIZE;
			dist[1][i][j] = MAX_SIZE;
		}
	}
	dist[0][1][1] = 1;
	visited[0][1][1] = true;
	BFS(1,1,false,N,M);
	result = min(dist[0][N][M], dist[1][N][M]);
	if(result == MAX_SIZE)
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<result<<"\n";
	}

}