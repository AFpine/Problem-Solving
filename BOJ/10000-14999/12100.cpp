#include <bits/stdc++.h>

// 12100 2048(Easy)

// update 220417

using namespace std;

static const int INF = 1e9+1;

int N;
int result = 0;
vector<vector<int>> board(21,vector<int>(21));

//0 is down, 1 is right, 2 is up, 3 is left

void right(vector<vector<int>>& board)
{
	bool check[21][21];
	int x,y;
	memset(check, false, sizeof(check));
	for(int i = 1;i<=N;++i)
	{
		for(int j = N;j>=1;--j)
		{
			if(board[i][j] != 0)
			{
				x = i;
				y = j;
				while(y+1 <= N)
				{
					if(board[x][y+1] == 0)
					{
						board[x][y+1] = board[x][y];
						board[x][y] = 0;
						if(check[x][y] == true)
						{
							check[x][y] = false;
							check[x][y+1] = true;
						}
					}
					else if(board[x][y+1] == board[x][y] && check[x][y] == false && check[x][y+1] == false)
					{
						check[x][y+1] = true;
						board[x][y+1] *= 2;
						board[x][y] = 0;
					}
					y++;
				}
			}
		}
	}
}

void left(vector<vector<int>>& board)
{
	bool check[21][21];
	int x,y;
	memset(check, false, sizeof(check));
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(board[i][j] != 0)
			{
				x = i;
				y = j;
				while(y-1 >= 1)
				{
					if(board[x][y-1] == 0)
					{
						board[x][y-1] = board[x][y];
						board[x][y] = 0;
						if(check[x][y] == true)
						{
							check[x][y] = false;
							check[x][y-1] = true;
						}
					}
					else if(board[x][y-1] == board[x][y] && check[x][y] == false && check[x][y-1] == false)
					{
						check[x][y-1] = true;
						board[x][y-1] *= 2;
						board[x][y] = 0;
					}
					y--;
				}
			}
		}
	}
}

void up(vector<vector<int>>& board)
{
	bool check[21][21];
	int x,y;
	memset(check, false, sizeof(check));
	for(int j = 1;j<=N;++j)
	{
		for(int i = 1;i<=N;++i)
		{
			if(board[i][j] != 0)
			{
				x = i;
				y = j;
				while(x-1 >= 1)
				{
					if(board[x-1][y] == 0)
					{
						board[x-1][y] = board[x][y];
						board[x][y] = 0;
						if(check[x][y] == true)
						{
							check[x][y] = false;
							check[x-1][y] = true;
						}
					}
					else if(board[x-1][y] == board[x][y] && check[x][y] == false && check[x-1][y] == false)
					{
						check[x-1][y] = true;
						board[x-1][y] *= 2;
						board[x][y] = 0;
					}
					x--;
				}
			}
		}
	}
}


void down(vector<vector<int>>& board)
{
	bool check[21][21];
	int x,y;
	memset(check, false, sizeof(check));
	for(int j = 1;j<=N;++j)
	{
		for(int i = N;i>=1;--i)
		{
			if(board[i][j] != 0)
			{
				x = i;
				y = j;
				while(x+1 <= N)
				{
					if(board[x+1][y] == 0)
					{
						board[x+1][y] = board[x][y];
						board[x][y] = 0;
						if(check[x][y] == true)
						{
							check[x][y] = false;
							check[x+1][y] = true;
						}
					}
					else if(board[x+1][y] == board[x][y] && check[x][y] == false && check[x+1][y] == false)
					{
						check[x+1][y] = true;
						board[x+1][y] *= 2;
						board[x][y] = 0;
					}
					x++;
				}
			}
		}
	}
}

void game2048(vector<vector<int>>& board, int turn)
{
	if(turn > 5)
	{
		int maximum = 0;
		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=N;++j)
			{
				if(board[i][j] > maximum)
				{
					maximum = board[i][j];
				}
			}
		}
		result = max(result,maximum);
		return;
	}

	vector<vector<int>> temp(21,vector<int>(21));

	temp = board;
	up(temp);
	game2048(temp,turn+1);

	temp = board;
	down(temp);
	game2048(temp,turn+1);
	
	temp = board;
	right(temp);
	game2048(temp,turn+1);
	
	temp = board;
	left(temp);
	game2048(temp,turn+1);

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
			cin>>board[i][j];
		}
	}

	game2048(board,1);

	cout<<result;

	return 0;
}