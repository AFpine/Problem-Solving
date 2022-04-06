#include <bits/stdc++.h>

// 2239 sudoku (Back tracking, implement)

// update 220328

using namespace std;

char board[9][9];

bool done = false;

void sudoku(deque<pair<int,int>>& dq)
{
	if(dq.empty() && done == false)
	{
		done = true;
		for(int i = 0;i<9;++i)
		{
			for(int j = 0;j<9;++j)
			{
				cout<<board[i][j];
			}
			cout<<"\n";
		}
		return;
	}

	bool row[10];
	bool col[10];
	bool sqr[10];

	pair<int,int> now = dq.front();
	dq.pop_front();
	int i = now.first;
	int j = now.second;
	for(int k = 0;k<10;++k)
	{
		row[k] = false;
		col[k] = false;
		sqr[k] = false;
	}
	for(int k = 0;k<9;++k)
	{
		row[board[i][k]-'0'] = true;
		col[board[k][j]-'0'] = true;
	}
	for(int k = (i/3)*3; k < (i/3)*3+3; ++k)
	{
		for(int h = (j/3)*3; h < (j/3)*3+3; ++h)
		{
			sqr[board[k][h]-'0'] = true;
		}
	}
	for(int k = 1;k<=9;++k)
	{
		if(row[k] == false && col[k] == false && sqr[k] == false)
		{
			board[now.first][now.second] = char('0'+k);
			sudoku(dq);
			if(done)
			{
				break;
			}
			board[now.first][now.second] = '0';
		}
	}
	dq.push_front(now);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	deque<pair<int,int>> dq;

	for(int i = 0;i<9;++i)
	{
		cin>>s;
		for(int j = 0;j<9;++j)
		{
			board[i][j] = s[j];
			if(board[i][j] == '0')
			{
				dq.push_back({i,j});
			}
		}
	}

	sudoku(dq);
	return 0;	
}