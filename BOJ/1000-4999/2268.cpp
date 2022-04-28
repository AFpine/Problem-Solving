#include <bits/stdc++.h>

// 2268 수들의 합 7

// update 220428

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 1000001;
const int MOD = 1000000007;

int N,M;
long long arr[MAX];
long long tree[MAX*4];


long long init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s];
	}
	
	int mid = (s+e)/2;

	return tree[node] = init(s,mid,node*2) + init(mid+1,e,node*2+1);
}

long long sum(int s, int e, int node, int l, int r)
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

void update(int s, int e, int node, int idx, long long k)
{
	if(s > idx || e < idx)
	{
		return;
	}

	tree[node] += k;

	if(s == e)
	{
		return;
	}
	
	int mid = (s+e)/2;

	update(s,mid,node*2,idx,k);
	update(mid+1,e,node*2+1,idx,k);
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	init(1,N,1);

	while(M--)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a == 0)
		{
			if(b > c)
			{
				cout<<sum(1,N,1,c,b)<<'\n';
			}
			else
			{
				cout<<sum(1,N,1,b,c)<<'\n';
			}
		}
		else
		{
			update(1,N,1,b,c-arr[b]);
			arr[b] = c;
		}
	}

	return 0;
}

