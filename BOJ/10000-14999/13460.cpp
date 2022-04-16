#include <bits/stdc++.h>

// 13460 Bead escape 2

// update 220416

using namespace std;

static const int INF = 1e9+1;

int N,M;
pair<int,int> hole;
char board[11][11];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//0 is down, 1 is right, 2 is up, 3 is left

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int result = INF;
	queue<pair<int,int>> redQ;
	queue<pair<int,int>> blueQ;
	queue<int> turnQ;
	
	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		cin>>s;
		for(int j = 1;j<=M;++j)
		{
			board[i][j] = s[j-1];
			if(board[i][j] == 'O')
			{
				hole = {i,j};
			}
			else if(board[i][j] == 'R')
			{
				redQ.push({i,j});
				board[i][j] = '.';
			}
			else if(board[i][j] == 'B')
			{
				blueQ.push({i,j});
				board[i][j] = '.';
			}
		}
	}

	turnQ.push(1);
	while(!redQ.empty())
	{
		pair<int,int> red = redQ.front();
		pair<int,int> blue = blueQ.front();
		int turn = turnQ.front();
		redQ.pop();
		blueQ.pop();
		turnQ.pop();

		if(turn > 10)
		{
			continue;
		}

		for(int dir = 0; dir<4; ++dir)
		{
			bool redchange = false;
			bool bluechange = false;
			bool redhole = false;
			bool meet = false;
			bool bluehole = false;
			int redx = red.first;
			int redy = red.second;
			int bluex = blue.first;
			int bluey = blue.second;

			while((redx+dx[dir] >= 1 && redx+dx[dir] <= N && redy+dy[dir] >= 1 && redy+dy[dir] <= M && bluex+dx[dir] >= 1 && bluex+dx[dir] <= N && bluey+dy[dir] >= 1 && bluey+dy[dir] <= M) && board[redx+dx[dir]][redy+dy[dir]] != '#')
			{
				meet = false;
				bluechange = false;
				if(board[redx+dx[dir]][redy+dy[dir]] == 'O')
				{
					redx += dx[dir];
					redy += dy[dir];
					redhole = true;
					break;
				}
				if(pair<int,int>(redx+dx[dir],redy+dy[dir]) == pair<int,int>(bluex,bluey))
				{
					meet = true;
					while((redx+dx[dir] >= 1 && redx+dx[dir] <= N && redy+dy[dir] >= 1 && redy+dy[dir] <= M && bluex+dx[dir] >= 1 && bluex+dx[dir] <= N && bluey+dy[dir] >= 1 && bluey+dy[dir] <= M) && board[bluex+dx[dir]][bluey+dy[dir]] != '#')
					{
						if(board[bluex+dx[dir]][bluey+dy[dir]] == 'O')
						{
							bluehole = true;
							break;
						}
						bluechange = true;
						bluex += dx[dir];
						bluey += dy[dir];
					}
				}
				if(meet == true && bluechange == false)
				{
					break;
				}
				redx += dx[dir];
				redy += dy[dir];
				redchange = true;
			}

			while((redx+dx[dir] >= 1 && redx+dx[dir] <= N && redy+dy[dir] >= 1 && redy+dy[dir] <= M && bluex+dx[dir] >= 1 && bluex+dx[dir] <= N && bluey+dy[dir] >= 1 && bluey+dy[dir] <= M) && board[bluex+dx[dir]][bluey+dy[dir]] != '#')
			{
				if(pair<int,int>(bluex+dx[dir],bluey+dy[dir]) == pair<int,int>(redx,redy))
				{
					if(board[bluex+dx[dir]][bluey+dy[dir]] == 'O')
					{
						bluehole = true;
					}
					break;
				}
				if(board[bluex+dx[dir]][bluey+dy[dir]] == 'O')
				{
					bluehole = true;
					break;
				}
				bluex += dx[dir];
				bluey += dy[dir];
				bluechange = true;
			}

			if(redhole == true && bluehole == false)
			{
				result = min(result,turn);
			}
			else if(bluehole == true)
			{
				continue;
			}
			else if(redchange == true || bluechange == true)
			{
				turnQ.push(turn+1);
				redQ.push({redx,redy});
				blueQ.push({bluex,bluey});
			}
		}	
	}

	if(result == INF)
	{
		cout<<"-1";
	}
	else
	{
		cout<<result;
	}

	

	return 0;
}