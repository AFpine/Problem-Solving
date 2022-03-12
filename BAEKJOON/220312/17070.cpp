#include <bits/stdc++.h>

// 17070 Pipe 1 (Dynamic Programming)

// update 220312

using namespace std;

int house[17][17];
int pipe[3][17][17];

void f0(int r, int c)
{
	if(house[r][c] == 1)
	{
		return;
	}
	pipe[0][r][c] = pipe[0][r][c] + pipe[0][r][c-1] + pipe[1][r][c-1];
}

void f1(int r, int c)
{
	if(house[r][c] == 1 || house[r-1][c] == 1 || house[r][c-1] == 1)
	{
		return;
	}
	pipe[1][r][c] = pipe[1][r][c] + pipe[0][r-1][c-1] + pipe[1][r-1][c-1] + pipe[2][r-1][c-1];
}

void f2(int r, int c)
{
	if(house[r][c] == 1)
	{
		return;
	}
	pipe[2][r][c] = pipe[2][r][c] + pipe[1][r-1][c] + pipe[2][r-1][c];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int res=0;
	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			cin>>house[i][j];
		}
	}
	pipe[0][1][2] = 1;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			f0(i,j);
			f1(i,j);
			f2(i,j);
		}
	}
	res = pipe[0][N][N] + pipe[1][N][N] + pipe[2][N][N];

	cout<<res<<"\n";

}
