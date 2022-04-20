#include <bits/stdc++.h>

// 14428 Sequence and query 16 (Segment tree)

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

int searchminidx(int start, int end, int i, int j, int node)
{
	if(i > end || j < start)
	{
		return 0;
	}
	if(start >= i && end <= j)
	{
		return tree[node];
	}

	int mid = (start+end)/2;
	int leftidx = searchminidx(start,mid,i,j,node*2);
	int rightidx = searchminidx(mid+1,end,i,j,node*2+1);
	if(arr[leftidx] < arr[rightidx])
	{
		return leftidx;
	}
	else if(arr[leftidx] == arr[rightidx] && leftidx < rightidx)
	{
		return leftidx;
	}
	else
	{
		return rightidx;
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

	arr[0] = INF;
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
			int s,e;
			cin>>s>>e;
			cout<<searchminidx(1,N,s,e,1)<<'\n';
		}
	}

	return 0;
}

