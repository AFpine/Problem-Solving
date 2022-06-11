#include <bits/stdc++.h>

// 1866 프리즌 브레이크

// update 220611

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 30005;
const int MOD = 1e9+7;
const int d = 105;

int N,M;
char prison[15][15];
vector<pair<int,int>> adj[MAX];
int personN, escN;
vector<pair<int,int>> escV;
map<pair<int,int>,int> personM;
map<pair<int,int>,int> escM;
bool visited[15][15];
queue<pair<int,int>> Q;

int A[MAX],B[MAX];
bool used[MAX];
vector<pair<int,int>> matchadj[MAX];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS()
{
	int dist[15][15];
	int escNum = escM[{Q.front().first, Q.front().second}];

	memset(dist,INF,sizeof(dist));
	dist[Q.front().first][Q.front().second] = 0;

	while(!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		for(int dir = 0;dir<4;++dir)
		{
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if(x < 1 || x > N || y < 1 || y > M)
			{
				continue;
			}
			if(prison[x][y] == 'X' || prison[x][y] == 'D')
			{
				continue;
			}
			if(visited[x][y] == false)
			{
				visited[x][y] = true;
				dist[x][y] = dist[cur.first][cur.second] + 1;
				adj[personM[{x,y}]].push_back({escNum,dist[x][y]});

				Q.push({x,y});
			}
		}
	}
}

bool dfs(int a, int k)
{
	if(used[a])
	{
		return false;
	}
	used[a] = true;
	for(auto &b : matchadj[a])
	{
		if(k < b.second)
		{
			continue;
		}
		if(B[b.first] == -1 || used[B[b.first]] == false && dfs(B[b.first],k) == true)
		{
			A[a] = b.first;
			B[b.first] = a;
			return true;
		}
	}
	return false;
}

bool bipartiteMatching(int k)
{
	fill(A,A+MAX,-1);
	fill(B,B+MAX,-1);
	fill(used,used+MAX,false);
	
	int match = 0;
	for(int i = 1;i<=personN;++i)
	{
		if(A[i] == -1)
		{
			fill(used,used+MAX,false);
			if(dfs(i, k))
			{
				match++;
			}
		}
	}

	if(match == personN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		string s;
		cin>>s;
		for(int j = 1;j<=M;++j)
		{
			prison[i][j] = s[j-1];
			if(prison[i][j] == '.')
			{
				personM[pair<int,int>(i,j)] = ++personN;
			}
			if(prison[i][j] == 'D')
			{
				escM[pair<int,int>(i,j)] = ++escN;
				escV.push_back({i,j});
			}
		}
	}

	for(auto &v : escV)
	{
		memset(visited,false,sizeof(visited));

		visited[v.first][v.second] = true;
		Q.push(v);

		BFS();
	}

	for(int i = 1;i<=personN;++i)
	{
		for(auto &p : adj[i])
		{
			for(int j = 0;j<=105;++j)
			{
				matchadj[i].push_back({p.first+(d*j), p.second+j});
			}
		}
	}//new B group initialize

	int result = -1;
	int l = 0, r = 200;
	while(l < r)
	{
		int mid = (l+r)/2;

		if(bipartiteMatching(mid))
		{
			result = mid;
			r = mid;
		}
		else
		{
			l = mid+1;
		}
	}

	if(result != -1)
	{
		cout<<result;
	}
	else
	{
		cout<<"impossible";
	}


	return 0;
}


