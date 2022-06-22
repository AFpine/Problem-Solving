#include <bits/stdc++.h>

// 9495 바둑

// update 220622

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 3005;
const long long MOD = 1e9+7;

int N;
int emptycnt, whitecnt;
bool visited[MAX];
int A[MAX],B[MAX];
map<pair<int,int>,int> emptyM, whiteM;
vector<pair<int,int>> whiteV;
vector<int> adj[MAX];
char GO[51][51];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool dfs(int a)
{
	if(visited[a])
	{
		return false;
	}
	visited[a] = true;
	for(auto &b : adj[a])
	{
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		string s;
		cin>>s;
		for(int j = 1;j<=N;++j)
		{
			GO[i][j] = s[j-1];
			if(GO[i][j] == 'o')
			{
				whiteM[pair<int,int>(i,j)] = ++whitecnt;
				whiteV.push_back({i,j});
			}
			else if(GO[i][j] == '.')
			{
				emptyM[pair<int,int>(i,j)] = ++emptycnt;
			}
		}
	}

	for(auto &p : whiteV)
	{
		for(int dir = 0;dir<4;++dir)
		{
			int x = p.first+dx[dir];
			int y = p.second+dy[dir];
			if(x < 1 || x > N || y < 1 || y > N)
			{
				continue;
			}
			if(GO[x][y] == '.')
			{
				adj[whiteM[{p.first,p.second}]].push_back(emptyM[{x,y}]);
			}
		}
	}

	fill(A,A+MAX,-1);
	fill(B,B+MAX,-1);
	int match = 0;
	for(int i = 1;i<=whitecnt;++i)
	{
		if(A[i] == -1)
		{
			fill(visited,visited+MAX,false);
			if(dfs(i))
			{
				match++;
			}
		}
	}

	cout<<whitecnt+emptycnt-match<<'\n';
	
	return 0;
}