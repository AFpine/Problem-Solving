#include <bits/stdc++.h>

// 2934 LRH 식물

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

void update(int s, int e, int node, int l, int r, int k)
{
	propagate(s,e,node);
	if(l > e || r < s)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] += k;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;
	update(s,mid,node*2,l,r,k);
	update(mid+1,e,node*2+1,l,r,k);

	tree[node] = tree[node*2] + tree[node*2+1];
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

	while(N--)
	{
		long long Ldaily = 0;
		long long Rdaily = 0;
		int L,R;

		cin>>L>>R;
		
		Ldaily += query(1,100000,1,L,L);
		Rdaily += query(1,100000,1,R,R);
		cout<<Ldaily+Rdaily<<'\n';
		update(1,100000,1,L,L,-Ldaily);
		update(1,100000,1,R,R,-Rdaily);
		update(1,100000,1,L+1,R-1,1);
	}
	

	return 0;
}

