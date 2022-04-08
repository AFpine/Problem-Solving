#include <bits/stdc++.h>

// 7579 APP (0-1 Knapsack Problem)

// update 220408

using namespace std;

static const int INF = 1e9+1;

int b[101];
int c[101];

int dp[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int maxsize=0;

    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        cin>>b[i];
    }

    for(int i = 1;i<=N;++i)
    {
        cin>>c[i];
        maxsize += c[i];
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 0;j<=maxsize;++j)
        {
            if(j >= c[i])
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]] + b[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 0;i<=maxsize;++i)
    {
        if(dp[N][i] >= M)
        {
            cout<<i<<'\n';
            break;
        }
    }



   
	return 0;
}