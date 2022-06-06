#include <bits/stdc++.h>

// 14245 XOR

// update 220606

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 500005;
const int MOD = 1e9+7;

int N,M;
long long arr[MAX];
long long tree[4*MAX], lazy[4*MAX];

int init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s];
	}

	int mid = (s+e)/2;

	return tree[node] = init(s,mid,node*2) + init(mid+1,e,node*2+1);
}

void propagate(int s, int e, int node)
{
	if(lazy[node] != 0)
	{
		tree[node] ^= lazy[node];
		if(s != e)
		{
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, int c)
{
	propagate(s,e,node);
	if(l > e || r < s)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] ^= c;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;

	update(s,mid,node*2,l,r,c);
	update(mid+1,e,node*2+1,l,r,c);

	tree[node] = tree[node*2] + tree[node*2+1];
}


int query(int s, int e, int node, int idx)
{
	propagate(s,e,node);
	if(idx < s || idx > e)
	{
		return 0;
	}
	if(s == e)
	{
		return tree[node];
	}
	int mid = (s+e)/2;

	return query(s,mid,node*2,idx) + query(mid+1,e,node*2+1,idx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
		cin>>q;
		if(q == 1)
		{		
			int a,b,c;
			cin>>a>>b>>c;
			update(1,N,1,a+1,b+1,c);
		}
		else
		{
			int a;
			cin>>a;
			cout<<query(1,N,1,a+1)<<'\n';
		}
	}

	return 0;
}

