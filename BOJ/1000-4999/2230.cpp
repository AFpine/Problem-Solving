#include <bits/stdc++.h>

// 2230 수 고르기

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M;
vector<int> arr;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end());

	if(M == 0)
	{
		cout<<"0";
		return 0;
	}

	int result = 2e9+1;

	int s = 0;
	int e = 0;

	while(s <= e && e <= N-1)
	{
		if(arr[e] - arr[s] >= M)
		{
			result = min(result,arr[e]-arr[s]);
		}

		if(arr[e]-arr[s] >= M)
		{
			s++;
		}
		else
		{
			e++;
		}

	}

	cout<<result;


	return 0;
}

