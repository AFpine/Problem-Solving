#include <bits/stdc++.h>

// 1507 궁금한 민호

// update 220509

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

int N;
int dist[21][21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag = false;
	int result = 0;
	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			cin>>dist[i][j];
		}
	}

	for(int k = 1;k<=N;++k)
	{
		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=N;++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					flag = true;
					break;
				}
			}
		}
	}

	for(int k = 1;k<=N;++k)
	{
		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=N;++j)
			{
				if(k == i || k == j)
				{
					continue;
				}
				if(dist[i][j] == dist[i][k] + dist[k][j])
				{
					dist[i][j] = INF;
				}
			}
		}
	}
	
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(dist[i][j] != INF)
			{
				result += dist[i][j];
			}
		}
	}

	if(flag)
	{
		cout<<"-1";
	}
	else
	{
		cout<<result/2;
	}

	return 0;
}

