#include <bits/stdc++.h>

// 9084 Coin (DP)

// update 220408

using namespace std;

static const int INF = 1e9+1;

int coin[21];
int DP[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin>>T;

    for(int t = 0;t<T;++t)
    {
        for(int i = 0;i<=10000;++i)
        {
            DP[i] = 0;
        }
        int N,M;
        cin>>N;
        for(int i = 1;i<=N;++i)
        {
            cin>>coin[i];
        }
        cin>>M;

        DP[0] = 1;
        for(int i = 1;i<=N;++i)
        {
            for(int j = coin[i];j<=M;++j)
            {
                DP[j] += DP[j-coin[i]];
            }
        }
        cout<<DP[M]<<"\n";
    }

   
	return 0;
}