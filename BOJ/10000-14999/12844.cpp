#include <bits/stdc++.h>

// 12844 XOR

// update 220603

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 500005;

int N,M;
int arr[MAX];
int tree[4*MAX], lazy[4*MAX];

int init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s];
	}
	int mid = (s+e)/2;
	return tree[node] = init(s,mid,node*2) ^ init(mid+1,e,node*2+1);
}

void propagate(int s, int e, int node)
{
	if(lazy[node] != 0)
	{
		if(s != e)
		{
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		if((e-s+1) % 2 == 1)
		{
			tree[node] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, int k)
{
	propagate(s,e,node);
	if(r < s || l > e)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] ^= k;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;
	update(s,mid,node*2,l,r,k);
	update(mid+1,e,node*2+1,l,r,k);
	tree[node] = tree[node*2] ^ tree[node*2+1];
}

int query(int s, int e, int node, int l, int r)
{
	propagate(s,e,node);
	if(r < s || l > e)
	{
		return 0;
	}
	if(l <= s && r >= e)
	{
		return tree[node];
	}
	int mid = (s+e)/2;
	return query(s,mid,node*2,l,r) ^ query(mid+1,e,node*2+1,l,r);
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
			int i,j,k;
			cin>>i>>j>>k;
			if(i > j) swap(i,j);
			update(1,N,1,i+1,j+1,k);
		}
		else
		{
			int i, j;
			cin>>i>>j;
			if(i > j) swap(i,j);
			cout<<query(1,N,1,i+1,j+1)<<'\n';
		}
	}
	

	return 0;
}

