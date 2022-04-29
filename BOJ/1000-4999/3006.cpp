#include <bits/stdc++.h>

// 3006 터보소트

// update 220429

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 100001;
const int MOD = 1000000007;

int N,M;
int seq[MAX];
int tree[MAX*4];

int init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = 1;
	}
	
	int mid = (s+e)/2;

	return tree[node] = init(s,mid,node*2) + init(mid+1,e,node*2+1);
}

int sum(int s, int e, int node, int l, int r)
{
	if(l > e || r < s)
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

void update(int s, int e, int node, int idx)
{
	if(s > idx || e < idx)
	{
		return;
	}

	tree[node] -= 1;

	if(s == e)
	{	
		tree[node] = 0;
		return;
	}
	
	int mid = (s+e)/2;

	update(s,mid,node*2,idx);
	update(mid+1,e,node*2+1,idx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	int temp;

	for(int i = 1;i<=N;++i)
	{
		cin>>temp;
		seq[temp] = i;
	}

	init(1,N,1);

	if(N%2 == 0)
	{
		for(int i = 1;i<N/2+1;++i)
		{
			cout<<sum(1,N,1,1,seq[i])-1<<'\n';
			update(1,N,1,seq[i]);

			if(i != N+1-i)
			{
				cout<<sum(1,N,1,seq[N+1-i],N)-1<<'\n';
				update(1,N,1,seq[N+1-i]);
			}
		}
	}
	else
	{
		for(int i = 1;i<=N/2+1;++i)
		{
			cout<<sum(1,N,1,1,seq[i])-1<<'\n';
			update(1,N,1,seq[i]);

			if(i != N+1-i)
			{
				cout<<sum(1,N,1,seq[N+1-i],N)-1<<'\n';
				update(1,N,1,seq[N+1-i]);
			}
		}
	}



	return 0;
}

