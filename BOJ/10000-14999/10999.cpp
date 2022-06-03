#include <bits/stdc++.h>

// 10999 구간 합 구하기 2

// update 220603

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;

int N,M,K;
long long arr[MAX];
long long tree[4*MAX], lazy[4*MAX];

long long init(int s, int e, int node)
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
		tree[node] += (e-s+1)*lazy[node];
		if(s != e)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, long long add)
{
	propagate(s,e,node);

	if(r < s || l > e)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] += add;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;

	update(s,mid,node*2,l,r,add);
	update(mid+1,e,node*2+1,l,r,add);
	tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(int s, int e, int node, int l, int r)
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
	return sum(s,mid,node*2,l,r) + sum(mid+1,e,node*2+1,l,r);
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

	int Q = M+K;
	while(Q--)
	{
		int q;
		cin>>q;
		if(q == 1)
		{
			int l, r;
			long long add;
			cin>>l>>r>>add;
			update(1,N,1,l,r,add);
		}
		else
		{
			int l, r;
			cin>>l>>r;
			cout<<sum(1,N,1,l,r)<<'\n';
		}
	}

	return 0;
}

