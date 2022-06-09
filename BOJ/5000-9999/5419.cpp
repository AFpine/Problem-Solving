#include <bits/stdc++.h>

// 5419 북서풍

// update 220609

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 75005;
const int MOD = 1e9+7;

int T;
int N;
pair<int,int> arr[MAX];
long long tree[MAX*4];
long long result;

void update(int s, int e, int node, int idx)
{
	if(idx > e || idx < s)
	{
		return;
	}
	if(s == e)
	{
		tree[node] += 1;
		return;
	}
	int mid = (s+e)/2;
	update(s,mid,node*2,idx);
	update(mid+1,e,node*2+1,idx);

	tree[node] = tree[node*2] + tree[node*2+1];
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

void init()
{
	result = 0;
	fill(tree,tree+(MAX*4),0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		init();

		cin>>N;
		for(int i = 1;i<=N;++i)
		{
			cin>>arr[i].first>>arr[i].second;
		}

		sort(arr+1,arr+1+N, [](pair<int,int> &a, pair<int,int> &b)
		{
			return a.second < b.second;
		});

		int maping[MAX];
		int newY = 1;
		for(int i = 1;i<=N;++i)
		{
			if(i > 1 && arr[i].second != arr[i-1].second)
			{
				newY++;
			}
			maping[i] = newY;
		}

		for(int i = 1;i<=N;++i)
		{
			arr[i].second =	maping[i];
		}

		sort(arr+1,arr+1+N, [](pair<int,int> &a, pair<int,int> &b)
		{
			if(a.first == b.first)
			{
				return a.second > b.second;
			}
			return a.first < b.first;
		});

		for(int i = 1;i<=N;++i)
		{
			result += sum(1,N,1,arr[i].second,N);
			update(1,N,1,arr[i].second);
		}

		cout<<result<<'\n';
	}


	return 0;
}


