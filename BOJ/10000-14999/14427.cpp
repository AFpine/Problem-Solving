#include <bits/stdc++.h>

// 14427 Sequence and query 15 (Segment tree)

// update 220420

using namespace std;

const int INF = 1e9+1;
const int minINF = -1e9-1;

int N,M;
int arr[100001];
int tree[100001*4];
int query;

int init(int start, int end, int node)
{
	if(start == end)
	{
		return tree[node] = start;
	}

	int mid = (start+end)/2;

	int leftidx = init(start,mid,node*2);
	int rightidx = init(mid+1,end,node*2+1);
	if(arr[leftidx] < arr[rightidx])
	{
		return tree[node] = leftidx;
	}
	else if(arr[leftidx] == arr[rightidx] && leftidx < rightidx)
	{
		return tree[node] = leftidx;
	}
	else
	{
		return tree[node] = rightidx;
	}
}

int update(int start, int end, int node, int idx)
{
	if(idx < start || idx > end || start == end)
	{
		return tree[node];
	}
	int mid = (start+end)/2;
	int leftidx = update(start,mid,node*2,idx);
	int rightidx = update(mid+1,end,node*2+1,idx);
	if(arr[leftidx] < arr[rightidx])
	{
		return tree[node] = leftidx;
	}
	else if(arr[leftidx] == arr[rightidx] && leftidx < rightidx)
	{
		return tree[node] = leftidx;
	}
	else
	{
		return tree[node] = rightidx;
	}
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
			int I,V;
			cin>>I>>V;
			arr[I] = V;
			update(1,N,1,I);
		}
		else if(query == 2)
		{
			cout<<tree[1]<<"\n";
		}
	}

	return 0;
}

