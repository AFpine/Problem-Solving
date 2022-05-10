#include <bits/stdc++.h>

// 1944 복제 로봇

// update 220510

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

struct Edge
{
	pair<int,int> u, v;
	int cost;
	bool operator<(const Edge& e)
	{
		return cost < e.cost;
	}
};

int N,M;
string s;
bool visited[51][51];
char maze[51][51];
pair<int,int> p[51][51];
vector<Edge> edge;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> find(pair<int,int> a)
{
	if(p[a.first][a.second] == pair<int,int>(-1,-1))
	{
		return a;
	}
	p[a.first][a.second] = find(p[a.first][a.second]);
	return p[a.first][a.second];
}


void merge(pair<int,int> a, pair<int,int> b)
{
	a = find(a);
	b = find(b);
	if(a == b)
	{
		return;
	}
	p[a.first][a.second] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int,int>> KQ;
	queue<pair<int,int>> Q;
	queue<int> distQ;
	queue<pair<int,int>> startQ;
	int result = 0;

	for(int i = 1;i<=50;++i)
	{
		for(int j = 1;j<=50;++j)
		{
			p[i][j] = {-1,-1};
			dist[i][j] = INF;
		}
	}

	cin>>N>>M;
	int m = 0;
	for(int i = 1;i<=N;++i)
	{
		cin>>s;
		for(int j = 1;j<=N;++j)
		{
			maze[i][j] = s[j-1];
			if(maze[i][j] == 'S')
			{
				KQ.push({i,j});
			}
			if(maze[i][j] == 'K')
			{
				KQ.push({i,j});
			}
		}
	}

	while(!KQ.empty())
	{
		for(int i = 1;i<=50;++i)
		{
			for(int j = 1;j<=50;++j)
			{
				visited[i][j] = false;
			}
		}

		Q.push(KQ.front());
		startQ.push(KQ.front());
		distQ.push(0);
		
		KQ.pop();

		while(!Q.empty())
		{
			pair<int,int> cur = Q.front();
			int curdist = distQ.front();
			pair<int,int> start = startQ.front();
			startQ.pop();
			Q.pop();
			distQ.pop();
			
			visited[cur.first][cur.second] = true;

			for(int dir = 0;dir<4;++dir)
			{
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];

				if(x < 1 || x > N || y < 1 || y > N)
				{
					continue;
				}
				if(maze[x][y] == '1')
				{
					continue;
				}
				if(visited[x][y] == true)
				{
					continue;
				}
				visited[x][y] = true;
				if(maze[x][y] == 'K')
				{
					edge.push_back({start,{x,y},curdist+1});
					Q.push({x,y});
					distQ.push(curdist+1);
					startQ.push(start);
				}
				if(maze[x][y] == '0')
				{
					Q.push({x,y});
					distQ.push(curdist+1);
					startQ.push(start);
				}
			}
		}
	}

	sort(edge.begin(),edge.end());

	for(auto &e : edge)
	{
		if(find(e.u) != find(e.v))
		{
			merge(e.u,e.v);
			result += e.cost;
			m++;
		}
		if(m == M)
		{
			break;
		}
	}

	if(m != M)
	{
		cout<<"-1";
	}
	else
	{
		cout<<result;
	}



	return 0;
}

