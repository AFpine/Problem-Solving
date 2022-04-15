#include <bits/stdc++.h>

// 1208 부분수열의 합 2 (Meet in the middle)

// update 220414

using namespace std;

static const int INF = 1e9+1;

int arr[41];
int N,S,half;
map<int,int> mimmap;
long long result;

void leftside(int index, int sum)
{
	if(index == half)
	{
		mimmap[sum]++;
		return;
	}
	leftside(index + 1, sum);
	leftside(index + 1, sum + arr[index]);
}

void rightside(int index, int sum)
{
	if(index == N)
	{
		result += mimmap[S-sum];
		return;
	}
	rightside(index + 1, sum);
	rightside(index + 1, sum + arr[index]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>S;

	half = N/2;

	for(int i = 0;i<N;++i)
	{
		cin>>arr[i];
	}

	leftside(0,0);
	rightside(half,0);

	if(S == 0)
	{//양쪽 다 공집합일 수 있으므로(문제 조건에 크기가 양수인 부분수열 만을 답으로 간주한다)
		cout<<result-1;
	}
	else
	{
		cout<<result;
	}

	return 0;
}