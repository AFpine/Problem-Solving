#include <bits/stdc++.h>

// 5398 틀렸습니다

// update 220527

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2010;

int T;
int H,V;
int x,y;
int cntMatch;
int crossidx[MAX][MAX];
char cross[MAX][MAX];
int cntH, cntV;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a)
{
	if(visited[a])
	{
		return false;
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
	cntMatch = 0;
	cntH = 0;
	cntV = 1000;
	memset(crossidx,-1,sizeof(crossidx));
	memset(cross,' ',sizeof(cross));
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

	cin>>T;
	while(T--)
	{
		init();

		cin>>H>>V;
		for(int i = 1;i<=H;++i)
		{
			string s;
			cin>>x>>y;
			cin>>s;
			++cntH;
			for(int j = 0;j<s.length();++j)
			{
				cross[y][x+j] = s[j];
				crossidx[y][x+j] = cntH;
			}
		}

		for(int i = 1;i<=V;++i)
		{
			string s;
			cin>>x>>y;
			cin>>s;
			++cntV;
			for(int j = 0;j<s.length();++j)
			{
				if((cross[y+j][x] != ' ') && (cross[y+j][x] != s[j]))
				{
					adj[crossidx[y+j][x]].push_back(cntV);
				}
			}
		}
		
		for(int i = 1;i<=cntH;++i)
		{
			if(A[i] == -1)
			{
				fill(visited,visited+MAX,false);
				if(dfs(i) == true)
				{
					cntMatch++;
				}
			}
		}

		cout<<H+V-cntMatch<<'\n';
	}

    
	return 0;
}

