#include <bits/stdc++.h>

// 1987 Alphabet (DFS)

// update 220328

using namespace std;

char board[21][21];
int dist[21][21];
bool alph[26];
pair<int,int> pre[21][21];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int totalcnt = 0;

void DFS(int R, int C, pair<int,int> now, int cnt)
{
	pair<int,int> temp;
	if(cnt > totalcnt)
	{
		totalcnt = cnt;
	}
	for(int dir = 0;dir<4;++dir)
	{
		int x = now.first + dx[dir];
		int y = now.second + dy[dir];
		temp = now;

		if(x<1 || x>R || y<1 || y>C)
		{
			continue;
		}
		
		if(alph[board[x][y]-'A'] == false)
		{
			alph[board[x][y] - 'A'] = true;
			DFS(R,C,{x,y},cnt+1);
			alph[board[x][y] - 'A'] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R,C;
	string s;
	pair<int,int> now;
	int result = 0;

	cin>>R>>C;

	for(int i = 1;i<=R;++i)
	{
		cin>>s;
		for(int j = 1;j<=C;++j)
		{
			pre[i][j] = {0,0};
			board[i][j] = s[j-1];
		}
	}

	alph[board[1][1] - 'A'] = true;
	DFS(R,C,{1,1},1);
	cout<<totalcnt<<'\n';

	return 0;	
}