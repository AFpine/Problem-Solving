#include <bits/stdc++.h>

// 10942 Palindrome?

// update 220411

using namespace std;

static const int INF = 1e9+1;

int arr[2001];
bool dp[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int S,E;

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        cin>>arr[i];
        dp[i][i] = true;
    }

    for(int i = 1;i<=N-1;++i)
    {
        if(arr[i] == arr[i+1])
        {
            dp[i][i+1] = true;
        }
    }
    for(int i = 2;i<=N-1;++i)
    {   
        for(int j = 1;j<=N-i;++j)
        {
            if(dp[j+1][j+i-1] == true && arr[j] == arr[j+i])
            {
                dp[j][j+i] = true;
            }
            else
            {
                dp[j][j+i] = false;
            }
        }
    }

    cin>>M;
    for(int i = 1;i<=M;++i)
    {
        cin>>S>>E;
        if(dp[S][E] == true)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
    }

    
	return 0;
}