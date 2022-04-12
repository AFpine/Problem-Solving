#include <bits/stdc++.h>

// 1509 Palindrome divide

// update 220412

using namespace std;

static const int INF = 1e9+1;

char palindrome[2501];
bool dp[2501][2501];

int result[2500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    string s;

    cin>>s;

    N = s.length();

    for(int i = 1;i<=N;++i)
    {
        palindrome[i] = s[i-1];
        dp[i][i] = true;
    }

    for(int i = 1;i<=N-1;++i)
    {
        if(palindrome[i] == palindrome[i+1])
        {
            dp[i][i+1] = true;
        }
    }
    for(int i = 2;i<=N-1;++i)
    {   
        for(int j = 1;j<=N-i;++j)
        {
            if(dp[j+1][j+i-1] == true && palindrome[j] == palindrome[j+i])
            {
                dp[j][j+i] = true;
            }
            else
            {
                dp[j][j+i] = false;
            }
        }
    }

    // we can get palindrome string (dp[s,e] is true) //#BOJ 10942

    for(int i = 1;i<=N;++i)
    {//result[i] is string[1,i]'s minimum palindrome divide value
        result[i] = INF;
        for(int j = 1;j<=i;++j)
        {
            if(dp[j][i] == true)
            {//if string[j,i] is palindrome
                if(result[i] > result[j-1] + 1)
                {//min(result[i], 1(because string[j,i]is palindrome) + string[1,j-1]'s minimum palindrome divide value)
                    result[i] = result[j-1] + 1;
                }
            }
        }
    }

    cout<<result[N];
    

    
	return 0;
}