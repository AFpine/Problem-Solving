#include <bits/stdc++.h>

using namespace std;

// 14002 Longest Increasing Subsequence

// update 220317

int arr[1000];
int LIS[1000];
stack<int> S[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int result=0;
	int max=0;
	stack<int> resultS;
	cin>>N;

	for(int i = 0;i<N;++i)
	{
		cin>>arr[i];
	}

	for(int k = 0;k<N;++k)
	{
		LIS[k] = 1;
		S[k].push(arr[k]);
		for(int i = 0;i<k;++i)
		{
			if(arr[i] < arr[k])
			{
				if(LIS[k] < LIS[i] + 1)
				{
					LIS[k] = LIS[i] + 1;
					S[i].push(arr[k]);
					S[k] = S[i];
					S[i].pop();
				}
				else
				{
					LIS[k] = LIS[k];
					S[k] = S[k];
				}
			}
		}
	}
	for(int i = 0;i<N;++i)
	{
		if(max < LIS[i])
		{
			max = LIS[i];
			result = i;
		}
	}

	cout<<LIS[result]<<"\n";
	while(!S[result].empty())
	{
		resultS.push(S[result].top());
		S[result].pop();
	}
	while(!resultS.empty())
	{
		cout<<resultS.top()<<" ";
		resultS.pop();
	}

}