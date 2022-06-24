#include <bits/stdc++.h>

// 20127 Y-수열

// update 220624

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

int N;
int arr[MAX];
//1 is increase, -1 is decrease, 0 is same

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int upcnt = 0, downcnt = 0;
	int upidx = 0, downidx = 0;

	cin>>N;
	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
	}

	for(int i = 2;i<=N;++i)
	{
		if(arr[i-1] < arr[i])
		{
			upcnt++;
			upidx = i-1;
		}
		if(arr[i-1] > arr[i])
		{
			downcnt++;
			downidx = i-1;
		}
	}

	if(upcnt > 1 || (upcnt == 1 && !(arr[N] >= arr[1])))
	{//감소 수열 불가능
		upidx = -1;
	}
	if(downcnt > 1 || (downcnt == 1 && !(arr[N] <= arr[1])))
	{//증가 수열 불가능
		downidx = -1;
	}

	int result;
	if(upidx != -1 && downidx != -1)
	{
		result = min(upidx, downidx);
	}
	else if(upidx != -1)
	{
		result = upidx;
	}
	else if(downidx != -1)
	{
		result = downidx;
	}
	else
	{
		result = -1;
	}

	cout<<result;

	return 0;
}

