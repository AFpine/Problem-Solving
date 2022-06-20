#include <bits/stdc++.h>

// 1022 소용돌이 예쁘게 출력하기

// update 220619

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 5005;
const int d = 5000;

int result[55][5];

int func(int r, int c)
{
	int a = max(abs(r), abs(c));
	int ret = (2*a+1)*(2*a+1);
	if(r == a)
	{
		return ret-(a-c);
	}
	ret -= (2*a);
	if(c == -a)
	{
		return ret-(a-r);
	}
	ret -= (2*a);
	if(r == -a)
	{
		return ret-(a+c);
	}
	ret -= (2*a);
	return ret-(a+r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r1,c1,r2,c2;
	int n = 0;

	cin>>r1>>c1>>r2>>c2;

	for(int i = r1;i<=r2;++i)
	{
		for(int j = c1;j<=c2;++j)
		{
			result[i-r1][j-c1] = func(i,j);
			n = max(n,result[i-r1][j-c1]);
		}
	}

	int k = 0;
	while(n > 0)
	{
		n /= 10;
		k++;
	}

	for(int i = 0;i<=r2-r1;++i)
	{
		for(int j = 0;j<=c2-c1;++j)
		{
			printf("%*d ",k,result[i][j]);
		}
		printf("\n");
	}



	

	return 0;
}