#include <bits/stdc++.h>

// 2042 구간 합 구하기 (segment tree)

// update 220422

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M,K;
long long i,j,k;
long long arr[1000001];
long long tree[4*1000001];

long long init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s];
	}

	int mid = (s+e)/2;

	return tree[node] = init(s,mid,node*2) + init(mid+1,e,node*2+1);
}

void update(int s, int e, int node, int idx, long long k)
{
	if(s>idx || e<idx)
	{
		return;
	}

	tree[node] += k;
	if(s==e)
	{
		return;
	}

	int mid = (s+e)/2;
	update(s,mid,node*2,idx,k);
	update(mid+1,e,node*2+1,idx,k);

}

long long sum(int s, int e, int node, int i, int j)
{
	if(s > j || e < i)
	{
		return 0;
	}

	if(i <= s && j >= e)
	{
		return tree[node];
	}

	int mid = (s+e)/2;

	return sum(s,mid,node*2,i,j) + sum(mid+1,e,node*2+1,i,j);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>K;
	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
	}
	
	init(1,N,1);

	for(int m = 1;m<=M+K;++m)
	{
		cin>>i;

		if(i == 1)
		{
			cin>>j>>k;
			update(1,N,1,j,k-arr[j]);
			arr[j] = k;
		}
		else
		{
			cin>>j>>k;
			cout<<sum(1,N,1,j,k)<<'\n';
		}
	}


	return 0;
}

