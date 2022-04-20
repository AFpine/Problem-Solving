#include <bits/stdc++.h>

// 18436 Sequence and query 37 (Segment tree)

// update 220420

using namespace std;

const int INF = 1e9+7;
const int minINF = -1e9-1;

int N,M;
int arr[100001];
int tree[100001*4];
int query;

int init(int start, int end, int node)
{
	if(start == end)
	{
		if(arr[start] % 2 == 1)
		{
			tree[node] = 1;
		}
		else
		{
			tree[node] = 0;
		}
		return tree[node];
	}

	int mid = (start+end)/2;

	return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

void update(int start, int end, int node, int idx, int diff)
{
	if(idx < start || idx > end)
	{
		return;
	}

	tree[node] += diff;
	if(start == end)
	{
		return;
	}
	int mid = (start+end)/2;
	update(start, mid, node*2, idx, diff);
	update(mid+1, end, node*2+1, idx, diff);

}

int sum(int start, int end, int node, int i, int j)
{
	if(j < start || i > end)
	{
		return 0;
	}
	if(i <= start && j >= end)
	{
		return tree[node];
	}
	int mid = (start+end)/2;
	return (sum(start,mid,node*2,i,j) + sum(mid+1,end,node*2+1,i,j));
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

	for(int i = 0;i<M;++i)
	{
		cin>>query;
		if(query == 1)
		{
			int I,X;
			cin>>I>>X;
			if(arr[I] % 2 == 0)
			{
				if(X % 2 == 1)
				{// +1
					update(1,N,1,I,1);
				}
			}
			else
			{
				if(X % 2 == 0)
				{// -1
					update(1,N,1,I,-1);
				}
			}
			arr[I] = X;
		}
		else if(query == 2)
		{
			int s,e;
			cin>>s>>e;
			cout<<(e-s+1)-sum(1,N,1,s,e)<<'\n';
		}
		else
		{
			int s,e;
			cin>>s>>e;
			cout<<sum(1,N,1,s,e)<<'\n';
		}
	}

	return 0;
}

