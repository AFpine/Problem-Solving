#include <bits/stdc++.h>

// 1806 sub sum

// update 220327

using namespace std;

int A[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int N,S;
	int left,right;
	int result  = 100001;
	int now;

	cin>>N>>S;

	for(int i = 1;i<=N;++i)
	{
		cin>>A[i];
	}

	left = 1;
	right = 1;
	
	now = A[right];

	while(left <= right && right <= N)
	{
		if(now >= S)
		{
			if(result > right - left + 1)
			{
				result = right - left + 1;
			}
			now -= A[left];
			left++;
		}
		else
		{
			right++;
			now += A[right];
		}
	}

	if(result != 100001)
	{
		cout<<result<<'\n';
	}
	else 
	{
		cout<<"0\n";
	}


	return 0;	
}