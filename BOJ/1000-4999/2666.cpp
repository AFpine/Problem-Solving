#include <bits/stdc++.h>

// 2666 벽장문의 이동 (Recursion Dynamic programming)

// update 220417

using namespace std;

static const int INF = 1e9+1;

int N,M;
int open1, open2;
int dp[21][21][21];
int arr[21];

int closet(int open1, int open2, int cnt)
{
	if(cnt > M)
	{
		return 0;
	}

	int returnvalue = dp[open1][open2][cnt];
	if(returnvalue != -1)
	{
		return returnvalue;
	}

	returnvalue = INF;

	returnvalue = min(closet(arr[cnt],open2,cnt+1)+abs(arr[cnt]-open1),closet(open1,arr[cnt],cnt+1)+abs(arr[cnt]-open2));
	dp[open1][open2][cnt] = returnvalue;
	return returnvalue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N;
	cin>>open1>>open2;
	cin>>M;

	for(int i = 1;i<=M;++i)
	{
		cin>>arr[i];
	}

	cout<<closet(open1,open2,1);

	return 0;
}