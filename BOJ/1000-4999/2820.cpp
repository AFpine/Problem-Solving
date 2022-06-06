#include <bits/stdc++.h>

// 2820 자동차 공장

// update 220606

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 500005;
const int MOD = 1e9+7;

int N,M;
int cnt;
vector<int> child[MAX];
int startIdx[MAX], endIdx[MAX];
long long arr[MAX];
long long tree[4*MAX], lazy[4*MAX];

void dfs(int cur)
{
	startIdx[cur] = ++cnt;
	for(auto &e : child[cur])
	{
		dfs(e);
	}
	endIdx[cur] = cnt;
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


long long query(int s, int e, int node, int idx)
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

	cin>>N>>M;
	cin>>arr[1];
	for(int i = 2;i<=N;++i)
	{
		int temp;
		cin>>arr[i]>>temp;
		child[temp].push_back(i);
	}
	dfs(1);

	for(int i = 1;i<=N;++i)
	{
		update(1,N,1,startIdx[i],startIdx[i],arr[i]);	
	}

	while(M--)
	{
		char op;
		cin>>op;

		if(op == 'p')
		{
			int a;
			long long x;
			cin>>a>>x;
			update(1,N,1,startIdx[a]+1,endIdx[a],x);
		}
		else
		{
			int a;
			cin>>a;
			cout<<query(1,N,1,startIdx[a])<<'\n';
		}
	}


	return 0;
}

