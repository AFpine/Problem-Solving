#include <bits/stdc++.h>

// 11505 구간 곱 구하기

// update 220427

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 1000001;
const int MOD = 1000000007;

int N,M,K;
long long arr[MAX];
long long tree[MAX*4];

long long init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s];
	}
	
	int mid = (s+e)/2;

	return tree[node] = (init(s,mid,node*2) * init(mid+1,e,node*2+1)) % MOD;
}

long long sum(int s, int e, int node, int l, int r)
{
	if(r < s || l > e)
	{
		return 1;
	}
	if(l <= s && r >= e)
	{
		return tree[node];
	}

	int mid = (s+e)/2;

	return (sum(s,mid,node*2,l,r)*sum(mid+1,e,node*2+1,l,r)) % MOD;
}

long long update(int s, int e, int node, int idx, long long k)
{
	if(idx < s || idx > e)
	{
		return tree[node];
	}

	if(s == e)
	{
		return tree[node] = k;
	}

	int mid = (s+e)/2;

	return tree[node] = (update(s,mid,node*2,idx,k) * update(mid+1,e,node*2+1,idx,k)) % MOD;
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

	for(int mk = 1;mk<=M+K;++mk)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a == 1)
		{
			if(arr[b] == 0)
			{
				arr[b] = (long long)c;
				init(1,N,1);
			}
			else
			{
				update(1,N,1,b,(long long)c);
				arr[b] = (long long)c;
			}
		}
		else
		{
			cout<<sum(1,N,1,b,c) % MOD<<'\n';
		}
	}
	return 0;
}

