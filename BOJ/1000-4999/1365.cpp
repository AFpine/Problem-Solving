#include <bits/stdc++.h>

// 1365 꼬인 전깃줄

// update 220429

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 100001;
const int MOD = 1000000007;

int N;
vector<pair<int,int>> arr;
int tree[MAX*4];

int init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = 0;
	}
	
	int mid = (s+e)/2;

	return tree[node] = max(init(s,mid,node*2),init(mid+1,e,node*2+1));
}

int getmax(int s, int e, int node, int l, int r)
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

	return max(getmax(s,mid,node*2,l,r),getmax(mid+1,e,node*2+1,l,r));
}

int update(int s, int e, int node, int idx, int k)
{
	if(s > idx || e < idx)
	{
		return -1;
	}

	if(s == e)
	{	
		return tree[node] = max(tree[node],k);
	}
	
	int mid = (s+e)/2;

	return tree[node] = max(tree[node], max(update(s,mid,node*2,idx,k),update(mid+1,e,node*2+1,idx,k)));
}

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first <= b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	int temp;
	int resultmax = 0;

	arr.push_back({0,0});
	for(int i = 1;i<=N;++i)
	{
		cin>>temp;
		arr.push_back({temp,i});
	}

	sort(arr.begin(),arr.end(),compare);

	init(1,N,1);

	for(int i = 1;i<=N;++i)
	{
		int tempmax;
		tempmax = getmax(1,N,1,1,arr[i].second-1);
		resultmax = max(resultmax,tempmax+1);
		update(1,N,1,arr[i].second,tempmax+1);
	}

	cout<<N-resultmax;

	return 0;
}

