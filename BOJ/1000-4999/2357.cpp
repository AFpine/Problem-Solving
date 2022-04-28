#include <bits/stdc++.h>

// 2357 최솟값과 최대값

// update 220428

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 1000001;
const int MOD = 1000000007;

int N,M;
int arr[MAX+1];
int maxtree[MAX*4];
int mintree[MAX*4];

int maxcompare(int a, int b)
{
	return (arr[a] > arr[b]) ? a : b;
}

int mincompare(int a, int b)
{
	return (arr[a] < arr[b]) ? a : b;
}


int maxinit(int s, int e, int node)
{
	if(s == e)
	{
		return maxtree[node] = s;
	}
	
	int mid = (s+e)/2;

	return maxtree[node] = maxcompare(maxinit(s,mid,node*2), maxinit(mid+1,e,node*2+1));
}

int mininit(int s, int e, int node)
{
	if(s == e)
	{
		return mintree[node] = s;
	}
	
	int mid = (s+e)/2;

	return mintree[node] = mincompare(mininit(s,mid,node*2), mininit(mid+1,e,node*2+1));
}

int getmax(int s, int e, int node, int l, int r)
{
	if(l > e || r < s)
	{
		return 0;
	}
	if(l <= s && r >= e)
	{
		return maxtree[node];
	}

	int mid = (s+e)/2;

	return maxcompare(getmax(s,mid,node*2,l,r), getmax(mid+1,e,node*2+1,l,r));
}

int getmin(int s, int e, int node, int l, int r)
{
	if(l > e || r < s)
	{
		return N+1;
	}
	if(l <= s && r >= e)
	{
		return mintree[node];
	}

	int mid = (s+e)/2;

	return mincompare(getmin(s,mid,node*2,l,r), getmin(mid+1,e,node*2+1,l,r));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
	}
	arr[0] = minINF;
	arr[N+1] = INF;

	maxinit(1,N,1);
	mininit(1,N,1);

	while(M--)
	{
		int a, b;
		cin>>a>>b;

		cout<<arr[getmin(1,N,1,a,b)]<<" "<<arr[getmax(1,N,1,a,b)]<<'\n';
	}
	
	return 0;
}

