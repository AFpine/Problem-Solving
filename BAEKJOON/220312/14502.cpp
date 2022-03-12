#include <bits/stdc++.h>

// 14502 Lab (BFS, BruteForce)

// update 220312

using namespace std;

int original[8][8];
int arr[8][8];
bool check[8][8];
int res=0;
int rescnt=0;

void BFS(queue<pair<int,int>>& q, int N, int M)
{
	int r,c;
	while(!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		
		if(r-1>=0 && arr[r-1][c] == 0)
		{
			arr[r-1][c] = 2;
			q.push({r-1,c});
		}
		if(r+1<N && arr[r+1][c] == 0)
		{
			arr[r+1][c] = 2;
			q.push({r+1,c});
		}
		if(c-1>=0 && arr[r][c-1] == 0)
		{	
			arr[r][c-1] = 2;
			q.push({r,c-1});
		}
		if(c+1<M && arr[r][c+1] == 0)
		{
			arr[r][c+1] = 2;
			q.push({r,c+1});
		}
	}
}

int result(queue<pair<int,int>>& q, int N, int M)
{
	int cnt=0;
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<M;++j)
		{
			if(arr[i][j] == 0)
			{
				++cnt;
			}
			if(check[i][j] == false)
			{
				arr[i][j] = original[i][j];
			}
			if(original[i][j] == 2)
			{
				q.push({i,j});
			}
		}
	}
	return cnt;
}

void virus(queue<pair<int,int>>& q, int N, int M)
{
	BFS(q, N, M);
	res = max(res,result(q,N,M));
}

void setwall(queue<pair<int,int>>& q, vector<pair<int,int>>& v, int N, int M,int idx, int num)
{
	if(num>=3)
	{
		virus(q,N,M);
		return;
	}
	for(int i = idx;i<v.size();++i)
	{
		if(arr[v[i].first][v[i].second] == 0)
		{
			check[v[i].first][v[i].second] = true;
			arr[v[i].first][v[i].second] = 1;
			setwall(q,v,N,M,i,num+1);
			check[v[i].first][v[i].second] = false;
			arr[v[i].first][v[i].second] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;	//N is row, M is column
	queue<pair<int,int>>q;
	vector<pair<int,int>>v;
	cin>>N>>M;

	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<M;++j)
		{
			cin>>original[i][j];
		}
	}
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<M;++j)
		{
			arr[i][j] = original[i][j];
			if(original[i][j] == 2)
			{
				q.push({i,j});
			}
			if(original[i][j] == 0)
			{
				v.push_back({i,j});
			}
		}
	}

	setwall(q,v,N,M,0,0);

	cout<<res<<"\n";
}
