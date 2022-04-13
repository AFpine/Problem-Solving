#include <bits/stdc++.h>

// 2133 Tile filling

// update 220413

using namespace std;

static const int INF = 1e9+1;

int tile[31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin>>N;

	tile[0] = 0;
	tile[1] = 0;
	tile[2] = 3;
	for(int i = 3;i<=N;++i)
	{
		if(i%2 == 1)
		{
			tile[i] = 0;
		}
		else
		{
			tile[i] += tile[2] * tile[i-2];
			for(int j = 4;j<=i;j+=2)
			{
				tile[i] += tile[i-j]*2;
			}
			tile[i] += 2;
		}
	}

	cout<<tile[N];
	

	return 0;
}