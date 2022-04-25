#include <bits/stdc++.h>

// 17435 합성함수와 쿼리

// update 220425

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int m;
int Q;
int n, x;
int binarymax = 19;

int f[200001][20];		//f[i][j] : f_(j+1)(i)


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>m;

	for(int i = 1;i<=m;++i)
	{
		cin>>f[i][0];
	}

	for(int j = 1;j<=binarymax;++j)
	{
		for(int i = 1;i<=m;++i)
		{
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}

	cin>>Q;

	while(Q--)
	{
		cin>>n>>x;

		for(int i = binarymax;i>=0;--i)
		{
			if(n == 0)
			{
				break;
			}
			if(n & 1<<i)
			{
				n -= 1<<i;
				x = f[x][i];
			}
		}

		cout<<x<<'\n';
	}

	return 0;
}

