#include <bits/stdc++.h>

// 2293 coin 1

// update 220411

using namespace std;

static const int INF = 1e9+1;

int coin[101];
int dp[10101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,k;

    cin>>n>>k;
    
    for(int i = 1;i<=n;++i)
    {
        cin>>coin[i];
    }

    dp[0] = 1;
    for(int i = 1;i<=n;++i)
    {
        for(int j = coin[i];j<=k;++j)
        {
            dp[j] += dp[j-coin[i]];
        }
    }

    cout<<dp[k];

   
	return 0;
}