#include <bits/stdc++.h>

// 13925 수열과 쿼리 13

// update 220605

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int MOD = 1e9+7;

int N,M;
long long arr[MAX];
long long tree[4*MAX], lazy1[4*MAX], lazy2[4*MAX];

long long init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s] % MOD;
	}
	int mid = (s+e)/2;
	return tree[node] = (init(s,mid,node*2) + init(mid+1,e,node*2+1)) % MOD;
}

void propagate(int s, int e, int node)
{
	if(lazy1[node] == 1 && lazy2[node] == 0)
	{
		return;
	}
	tree[node] = (tree[node]*lazy1[node] + (e-s+1)*lazy2[node]) % MOD;
	if(s != e)
	{
		lazy1[node*2] = (lazy1[node*2]*lazy1[node]) % MOD;
		lazy2[node*2] = (lazy2[node*2]*lazy1[node]+lazy2[node]) % MOD;
		lazy1[node*2+1] = (lazy1[node*2+1]*lazy1[node]) % MOD;
		lazy2[node*2+1] = (lazy2[node*2+1]*lazy1[node]+lazy2[node]) % MOD;
	}
	lazy1[node] = 1;
	lazy2[node] = 0;
}

void update(int s, int e, int node, int l, int r, long long a, long long b)
{
	propagate(s,e,node);
	if(l > e || r < s)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		// lazy1[node] = a;
		// lazy2[node] = b;
		lazy1[node] = (lazy1[node] * a) % MOD;
		lazy2[node] = (lazy2[node]*a+b) % MOD;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;

	update(s,mid,node*2,l,r,a,b);
	update(mid+1,e,node*2+1,l,r,a,b);
	tree[node] = (tree[node*2] + tree[node*2+1]) % MOD;
}


long long query(int s, int e, int node, int l, int r)
{
	propagate(s,e,node);
	if(l > e || r < s)
	{
		return 0;
	}
	if(l <= s && r >= e)
	{
		return tree[node] % MOD;
	}

	int mid = (s+e)/2;

	return (query(s,mid,node*2,l,r) + query(mid+1,e,node*2+1,l,r)) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<4*MAX;++i)
	{
		lazy1[i] = 1;
		lazy2[i] = 0;
	}

	cin>>N;
	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
	}

	init(1,N,1);

	cin>>M;

	while(M--)
	{
		int q;
		int x,y;
		long long v;

		cin>>q;
		if(q == 1)
		{
			cin>>x>>y>>v;
			update(1,N,1,x,y,1,v);
		}
		else if(q == 2)
		{
			cin>>x>>y>>v;
			update(1,N,1,x,y,v,0);
		}
		else if(q == 3)
		{
			cin>>x>>y>>v;
			update(1,N,1,x,y,0,v);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,N,1,x,y)<<'\n';
		}
	}


	return 0;
}

