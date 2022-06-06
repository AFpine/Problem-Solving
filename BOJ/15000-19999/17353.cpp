#include <bits/stdc++.h>

// 17353 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별

// update 220606

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int MOD = 1e9+7;

int N,Q;
long long arr[MAX], tree[4*MAX], lazy[4*MAX];

void propagate(int s, int e, int node)
{
	if(lazy[node] != 0)
	{
		tree[node] += (e-s+1)*lazy[node];
		if(s != e)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, long long x)
{
	propagate(s,e,node);
	if(l > e || r < s)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] += x;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;

	update(s,mid,node*2,l,r,x);
	update(mid+1,e,node*2+1,l,r,x);

	tree[node] = tree[node*2] + tree[node*2+1];
}


long long query(int s, int e, int node, int l, int r)
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

	return query(s,mid,node*2,l,r) + query(mid+1,e,node*2+1,l,r);
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
	for(int i = 1;i<=N;++i)
	{
		update(1,N,1,i,i,arr[i]-arr[i-1]);
	}
	
	cin>>Q;

	while(Q--)
	{
		int q;
		cin>>q;
		if(q == 1)
		{
			int l,r;
			cin>>l>>r;
			update(1,N,1,l,r,1);
			update(1,N,1,r+1,r+1,-(r-l+1));
		}
		else
		{
			int x;
			cin>>x;
			cout<<query(1,N,1,1,x)<<'\n';
		}
	}

	return 0;
}

