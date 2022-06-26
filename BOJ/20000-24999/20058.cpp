#include <bits/stdc++.h>

// 20058 마법사 상어와 파이어스톰

// update 220626

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 65;
const int MOD = 1e9+7;

int N,Q;
int arr[MAX][MAX];
int temp[MAX][MAX];
int uf[10005];
bool melt[MAX][MAX];
map<pair<int,int>,int> M;
int icecnt;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int find(int a)
{
	if(uf[a] < 0)
	{
		return a;
	}
	return uf[a] = find(uf[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)
	{
		return;
	}
	uf[a] += uf[b];
	uf[b] = a;
}


void rotate(int y, int x, int L)
{
	for(int i = 0;i<L;++i)
	{
		for(int j = 0;j<L;++j)
		{
			temp[i][j] = arr[y+L-1-j][x+i];
		}
	}
	for(int i = 0;i<L;++i)
	{
		for(int j = 0;j<L;++j)
		{
			arr[y+i][x+j] = temp[i][j];
		}
	}
}

void checkMelt()
{
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(arr[i][j] <= 0)
			{
				continue;
			}
			int adj = 0;
			for(int dir = 0;dir<4;++dir)
			{
				int x = i+dx[dir];
				int y = j+dy[dir];
				if(x < 1 || x > N || y < 1 || y > N)
				{
					continue;
				}
				if(arr[x][y] > 0)
				{
					adj++;
				}
			}
			if(adj < 3)
			{
				melt[i][j] = true;
			}
		}
	}
}

void melting()
{
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(melt[i][j])
			{
				arr[i][j]--;
			}
		}
	}
}

int result()
{
	int ret = 0;
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(arr[i][j])
			{
				M[pair<int,int>(i,j)] = ++icecnt;
				ret += arr[i][j];
			}
		}
	}
	return ret;
}

int bigIce()
{
	int result = 0;
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(arr[i][j] <= 0)
			{
				continue;
			}
			for(int dir = 0;dir<4;++dir)
			{
				int x = i+dx[dir];
				int y = j+dy[dir];
				if(x < 1 || x > N || y < 1 || y > N)
				{
					continue;
				}
				if(arr[x][y] > 0)
				{
					if(find(M[{i,j}]) != find(M[{x,y}]))
					{
						merge(M[{i,j}], M[{x,y}]);
						result = max(result, -uf[find(M[{x,y}])] );
					}
				}
			}
		}
	}
	return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf,uf+10005,-1);

	cin>>N>>Q;
	N = pow(2,N);

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			cin>>arr[i][j];
		}
	}

	for(int i = 1;i<=Q;++i)
	{
		memset(melt,false,sizeof(melt));
		int L;
		int pL;
		cin>>L;
		L = (1<<L);

		for(int i = 1;i<=N;i+=L)
		{
			for(int j = 1;j<=N;j+=L)
			{
				rotate(i,j,L);
			}
		}


		checkMelt();
		melting();
	}

	cout<<result()<<'\n';

	cout<<bigIce()<<'\n';

	return 0;
}

