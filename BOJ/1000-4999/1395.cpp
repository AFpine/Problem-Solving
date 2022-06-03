#include <bits/stdc++.h>

// 1395 스위치

// update 220603

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int N,M;
int arr[MAX];
int tree[4*MAX];
bool lazy[4*MAX];

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
		tree[node] = (e-s+1)-tree[node];
		if(s != e)
		{
			lazy[node*2] = !lazy[node*2];
			lazy[node*2+1] = !lazy[node*2+1];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r)
{
	propagate(s,e,node);
	if(r < s || l > e)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] = !lazy[node];
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;
	update(s,mid,node*2,l,r);
	update(mid+1,e,node*2+1,l,r);
	tree[node] = tree[node*2] + tree[node*2+1];
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
	return query(s,mid,node*2,l,r) + query(mid+1,e,node*2+1,l,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		arr[i] = 0;
	}
	init(1,N,1);

	while(M--)
	{
		int q,s,t;
		cin>>q>>s>>t;
		
		if(q == 0)
		{
			update(1,N,1,s,t);
		}
		else
		{
			cout<<query(1,N,1,s,t)<<'\n';
		}
	}

	return 0;
}

