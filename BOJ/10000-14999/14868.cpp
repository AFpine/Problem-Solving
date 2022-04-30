#include <bits/stdc++.h>

// 14868 문명

// update 220430

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,K;
pair<int,int> p[2001][2001];
int civilsize[2001][2001];
bool visited[2001][2001];
queue<pair<int,int>> Q;
queue<pair<int,int>> tempQ;
int year = 0;
int visitedcnt = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> find(pair<int,int> a)
{
	if(p[a.first][a.second] == pair<int,int>(-1,-1))
	{
		return a;
	}
	else
	{
		p[a.first][a.second] = find(p[a.first][a.second]);
		return p[a.first][a.second];
	}
}

void merge(pair<int,int> v, pair<int,int> w)
{
	v = find(v);
	w = find(w);

	if(v == w)
	{
		return;
	}

	civilsize[v.first][v.second] += civilsize[w.first][w.second];
	p[w.first][w.second] = v;
}

void bfs()
{
	while(!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		
		for(int dir = 0;dir<4;++dir)
		{
			int x = cur.first+dx[dir];
			int y = cur.second+dy[dir];

			if(x < 1 || x > N || y < 1 || y > N)
			{
				continue;	
			}

			if(visited[x][y] == false)
			{
				visited[x][y] = true;
				visitedcnt++;
				tempQ.push({x,y});
				merge(cur,{x,y});
			}
			else if(find(cur) != find({x,y}))
			{
				merge(cur,{x,y});
			}
		}
	}
}


bool checkcivil()
{
	Q = tempQ;
	while(!tempQ.empty())
	{
		int i = tempQ.front().first;
		int j = tempQ.front().second;
		tempQ.pop();

		for(int dir = 0;dir<4;++dir)
		{
			int x = i+dx[dir];
			int y = j+dy[dir];
			if(x < 1 || x > N || y < 1 || y > N)
			{
				continue;
			}
			if(visited[x][y] == true && (find({i,j}) != find({x,y})))
			{
				merge({i,j},{x,y});
			}
		}
		if(civilsize[find({i,j}).first][find({i,j}).second] == visitedcnt)
		{
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

	cin>>N>>K;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			p[i][j] = {-1,-1};
			civilsize[i][j] = 1;
		}
	}

	for(int i = 1;i<=K;++i)
	{
		int x,y;
		cin>>x>>y;
		tempQ.push({x,y});
		visited[x][y] = true;
		visitedcnt++;
	}

	while(true)
	{
		if(checkcivil() == true)
		{
			cout<<year;
			break;
		}
		else
		{
			bfs();
		}
		year++;
	}

	return 0;
}

