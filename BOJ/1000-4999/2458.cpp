#include <bits/stdc++.h>

// 2458 키 순서

// update 220506

using namespace std;

const int INF = 1e9+5;
const int minINF = -2e9-1;

int N,M;
int dist[501][501];
int smaller[501];
int taller[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1;i<=500;++i)
	{
		smaller[i] = 0;
		taller[i] = 0;
		for(int j = 1;j<=500;++j)
		{
			dist[i][j] = INF;
		}
	}

	int result = 0;

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		int a,b;
		cin>>a>>b;
		dist[a][b] = 1;
	}

	for(int k = 1;k<=N;++k)
	{
		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=N;++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
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
				smaller[j]++;
				taller[i]++;
			}
		}
	}

	for(int i = 1;i<=N;++i)
	{
		if(smaller[i] + taller[i] == N-1)
		{
			result++;
		}
	}
	
	cout<<result;
	
	return 0;
}

