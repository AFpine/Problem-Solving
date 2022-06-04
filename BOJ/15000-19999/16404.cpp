#include <bits/stdc++.h>

// 16404 주식회사 승범이네

// update 220604

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int N,M;
int cntVertex = 0;
int arr[MAX], parent[MAX], startIdx[MAX], endIdx[MAX];
vector<int> child[MAX];
int tree[MAX*4], lazy[MAX*4];

void dfs(int cur)
{
	startIdx[cur] = ++cntVertex;
	for(auto &e : child[cur])
	{
		dfs(e);
	}
	endIdx[cur] = cntVertex;
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

	fill(arr,arr+MAX,0);
	fill(parent,parent+MAX,-1);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		int parent;
		cin>>parent;
		child[parent].push_back(i);
	}

	dfs(1);

	while(M--)
	{
		int q;
		cin>>q;
		if(q == 1)
		{
			int i,w;
			cin>>i>>w;
			update(1,N,1,startIdx[i],endIdx[i],w);
		}
		else
		{
			int i;
			cin>>i;
			cout<<query(1,N,1,startIdx[i])<<'\n';
		}



	}


	return 0;
}

