#include <bits/stdc++.h>

using namespace std;

// 11054 Longest bitonic subsequence (LIS + LDS)

// update 220317

int LIS[1000];
int LDS[1000];
int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int result=0;
	cin>>N;

	for(int i = 0;i<N;++i)
	{
		cin>>arr[i];
	}

	for(int k = 0;k<N;++k)
	{
		LIS[k] = 1;
		for(int i = 0;i<k;++i)
		{
			if(arr[i] < arr[k])
			{
				LIS[k] = max(LIS[k], LIS[i] + 1);
			}
		}
	}

	for(int k = N-1;k>=0;--k)
	{
		LDS[k] = 1;
		for(int i = N-1;i>k;--i)
		{
			if(arr[i] < arr[k])
			{
				LDS[k] = max(LDS[k], LDS[i] + 1);
			}
		}
	}

	for(int i = 0;i<N;++i)
	{
		if(result < LIS[i] + LDS[i])
		{
			result = LIS[i] + LDS[i];
		}
	}
	cout<<result-1<<"\n";

}