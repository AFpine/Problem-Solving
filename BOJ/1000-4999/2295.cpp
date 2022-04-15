#include <bits/stdc++.h>

// 2295 sum of three numbers

// update 220414

using namespace std;

static const int INF = 1e9+1;

vector<int> arr;
vector<int> X;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num;
	int result = 0;
	cin>>N;

	for(int i = 0;i<N;++i)
	{
		cin>>num;
		arr.push_back(num);
	}

	sort(arr.begin(),arr.begin()+N);

	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			X.push_back(arr[i] + arr[j]);
		}
	}

	sort(X.begin(),X.end());

	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			if(binary_search(X.begin(),X.end(),arr[i]-arr[j]))
			{
				result = max(result, arr[i]);
			}
		}
	}

	cout<<result;

	return 0;
}