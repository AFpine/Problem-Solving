#include <bits/stdc++.h>

// 9527 Counting 1 bit
// bit 연산을 할 때, 자료형을 잘 맞춰줘야 한다 (1을 shift 할 때, long long에 비교할거면 1LL을 꼭 해줘야 함)

// update 220413

using namespace std;

static const int INF = 1e9+1;

long long dp[57];

long long counting1bits(long long N)
{
	long long result = 0;
	int countbit = 0;
	long long temp = N;
	while(temp != 0)
	{
		temp /= 2;
		countbit++;
	}
	countbit--;
	temp = N;
	while(countbit > 0)
	{
		if(temp & 1LL<<countbit)		//1<<countbit is 2^(countbit)
		{
			result += dp[countbit-1] + (temp - (1LL<<countbit)) + 1LL;
			temp -= (1LL<<countbit);
		}
		countbit--;
	}
	if(N & 1)
	{
		result += 1LL;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A,B;

	cin>>A>>B;
	
	dp[0] = 1;
	for(int i = 1;i<=56;++i)
	{
		dp[i] = dp[i-1]*(long long)2 + (1LL<<i);
	}
	//dp[i] : 2^(i+1)-1 까지의 1 비트 개수 누적합 == 비트가 i+1 개 까지 있는 값들의 1비트 개수 누적합

	cout<<(long long)(counting1bits(B)-counting1bits(A-1))<<'\n';

	return 0;
}