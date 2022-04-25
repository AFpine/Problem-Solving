#include <bits/stdc++.h>

// 3117 YouTube (Sparse table)

// update 220425

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int BINARY_MAX = 30;

int N,K,M;
int student[100001];
int youtube[100001][BINARY_MAX+1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K>>M;

	for(int i = 1;i<=N;++i)
	{
		cin>>student[i];
	}

	for(int i = 1;i<=K;++i)
	{
		cin>>youtube[i][0];
	}

	for(int j = 1;j<=BINARY_MAX;++j)
	{
		for(int i = 1;i<=K;++i)
		{
			youtube[i][j] = youtube[youtube[i][j-1]][j-1];
		}
	}

	for(int i = 1;i<=N;++i)
	{
		int x = student[i];
		int m = M-1;
		for(int j = BINARY_MAX;j>=0;--j)
		{
			if(m == 0)
			{
				break;
			}
			if(m & 1<<j)
			{
				m -= 1<<j;
				x = youtube[x][j];
			}
		}
		cout<<x<<" ";
	}

	return 0;
}

