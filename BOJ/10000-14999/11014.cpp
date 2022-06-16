#include <bits/stdc++.h>

// 11014 컨닝 2

// update 220616

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 6405;

int C;
int N,M;
int sitNum;
int cntMatch;
char classroom[85][85];
map<pair<int,int>,int> maping;
vector<int> adj[MAX];
int A[MAX],B[MAX];
bool visited[MAX];
vector<int> oddV;

bool dfs(int a)
{
	if(visited[a])
	{
		return true;
	}
	visited[a] = true;
	for(auto &b : adj[a])
	{
		if(B[b] == -1 || (visited[B[b]] == false && dfs(B[b]) == true))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void init()
{
	sitNum = 0;
	cntMatch = 0;
	maping.clear();
	oddV.clear();
	for(int i = 0;i<MAX;++i)
	{
		A[i] = -1;
		B[i] = -1;
		adj[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>C;
	while(C--)
	{
		init();

		cin>>N>>M;
		for(int i = 1;i<=N;++i)
		{
			string s;
			cin>>s;
			for(int j = 1;j<=M;++j)
			{
				classroom[i][j] = s[j-1];
				if(classroom[i][j] == '.')
				{
					maping[pair<int,int>(i,j)] = ++sitNum;
					if(j % 2 == 1)
					{
						oddV.push_back(sitNum);
					}
				}
			}
		}

		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=M;++j)
			{
                if(j % 2 == 0)
                {
                    continue;
                }
				if(classroom[i][j] == 'x')
				{
					continue;
				}

				if(i > 1 && j > 1 && (classroom[i-1][j-1] != 'x'))
				{
					adj[maping[pair<int,int>(i,j)]].push_back(maping[pair<int,int>(i-1,j-1)]);
				}
				if(j > 1 && (classroom[i][j-1] != 'x'))
				{
					adj[maping[pair<int,int>(i,j)]].push_back(maping[pair<int,int>(i,j-1)]);
				}
				if(i > 1 && j < M && (classroom[i-1][j+1] != 'x'))
				{
					adj[maping[pair<int,int>(i,j)]].push_back(maping[pair<int,int>(i-1,j+1)]);
				}
				if(j < M && (classroom[i][j+1] != 'x'))
				{
					adj[maping[pair<int,int>(i,j)]].push_back(maping[pair<int,int>(i,j+1)]);
				}
				if(i < N && j > 1 && (classroom[i+1][j-1] != 'x'))
				{
					adj[maping[pair<int,int>(i,j)]].push_back(maping[pair<int,int>(i+1,j-1)]);
				}
				if(i < N && j < M && (classroom[i+1][j+1] != 'x'))
				{
					adj[maping[pair<int,int>(i,j)]].push_back(maping[pair<int,int>(i+1,j+1)]);
				}
			}
		}

		for(auto &i : oddV)
		{
			if(A[i] == -1)
			{
				fill(visited,visited+MAX,false);
				if(dfs(i))
				{
					++cntMatch;
				}
			}
		}

		cout<<sitNum-cntMatch<<'\n';
	}
    
	return 0;
}

