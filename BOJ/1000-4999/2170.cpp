#include <bits/stdc++.h>

// 2170 선 긋기

// update 220609

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

int N;
pair<int,int> arr[MAX];
long long result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i].first>>arr[i].second;
	}

	sort(arr+1,arr+1+N);

	int S = arr[1].first;
	int E = arr[1].second;
	for(int i = 2;i<=N;++i)
	{
		if(arr[i].first > E)
		{
			result += (E-S);
			S = arr[i].first;
			E = arr[i].second;
		}
		else
		{
			if(arr[i].second > E)
			{
				E = arr[i].second;
			}
		}
	}
	result += (E-S);

	cout<<result;

	return 0;
}


