#include <bits/stdc++.h>

// 1949 Good Village

// update 220421

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

struct Village
{
	int popu;
	vector<int> edge;
};

int N;
Village vill[10001];
int dp[2][10001];
bool visited[10001];
//0 is not good village, 1 is good village (about start(root) node)

void traverse(int cur)
{
	dp[0][cur] = 0;
	dp[1][cur] = vill[cur].popu;

	for(auto x : vill[cur].edge)
	{
		if(visited[x] == false)
		{
			visited[x] = true;
			traverse(x);

			dp[0][cur] += max(dp[1][x], dp[0][x]);

			dp[1][cur] += dp[0][x];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=10000;++i)
	{
		dp[0][i] = -1;
		dp[1][i] = -1;
	}

	for(int i = 1;i<=N;++i)
	{
		cin>>vill[i].popu;
	}

	for(int i = 1;i<=N-1;++i)
	{
		int a,b;
		cin>>a>>b;

		vill[a].edge.push_back(b);
		vill[b].edge.push_back(a);

	}

	visited[1] = true;

	traverse(1);

	cout<<max(dp[0][1], dp[1][1]);


	return 0;
}

