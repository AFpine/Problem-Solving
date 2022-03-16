#include <bits/stdc++.h>

using namespace std;
// 2638 Cheese (BFS)

// update 220316


int mono[100][100];
//1 is cheese, 0 is nothing(not cheese)
bool visited[100][100];

void airBFS(int N, int M)
{
	queue<pair<int,int>>q;
	q.push({0,0});
	visited[0][0] = true;
	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if(i>0 && (mono[i-1][j] == 0 || mono[i-1][j] == -1 ) && visited[i-1][j] == false)
		{
			mono[i-1][j] = -1;
			visited[i-1][j] = true;
			q.push({i-1,j});
		}
		if(j>0 && (mono[i][j-1] == 0 || mono[i][j-1] == -1 ) && visited[i][j-1] == false)
		{
			mono[i][j-1] = -1;
			visited[i][j-1] = true;
			q.push({i,j-1});
		}
		if(i+1<N && (mono[i+1][j] == 0 || mono[i+1][j] == -1 ) && visited[i+1][j] == false)
		{
			mono[i+1][j] = -1;
			visited[i+1][j] = true;
			q.push({i+1,j});
		}
		if(j+1<M && (mono[i][j+1] == 0 || mono[i][j+1] == -1 ) && visited[i][j+1] == false)
		{
			mono[i][j+1] = -1;
			visited[i][j+1] = true;
			q.push({i,j+1});
		}
	}
}

void erasecheese(set<pair<int,int>>& cheese)
{
	int cnt;
	int i,j;
	vector<set<pair<int,int>>::iterator>v;
	for(auto it = cheese.begin(); it != cheese.end(); ++it)
	{
		cnt = 0;
		i = (*it).first;
		j = (*it).second;
		if(mono[i-1][j] == -1)
		{
			++cnt;
		}
		if(mono[i+1][j] == -1)
		{
			++cnt;
		}
		if(mono[i][j-1] == -1)
		{
			++cnt;
		}
		if(mono[i][j+1] == -1)
		{
			++cnt;
		}
		if(cnt >= 2)
		{
			mono[i][j] = 0;
			v.push_back(it);
		}
	}
	for(auto x : v)
	{
		cheese.erase(x);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;
	set<pair<int,int>> cheese;
	int hour=0;
	cin>>N>>M;

	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<M;++j)
		{
			cin>>mono[i][j];
			if(mono[i][j] == 1)
			{
				cheese.insert({i,j});
			}
		}
	}


	while(!cheese.empty())
	{
		for(int i = 0;i<N;++i)
		{
			for(int j = 0;j<M;++j)
			{
				visited[i][j] = false;
			}
		}
		airBFS(N,M);
		erasecheese(cheese);
		++hour;
	}
	
	cout<<hour<<"\n";


}