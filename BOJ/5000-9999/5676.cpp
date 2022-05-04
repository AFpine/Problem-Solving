#include <bits/stdc++.h>

// 5676 음주 코딩

// update 220503

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 100001;

int N,K;
int arr[MAX];
int tree[MAX*4];

int init(int s, int e, int node)
{
	if(s == e)
	{
		return tree[node] = arr[s];
	}

	int mid = (s+e)/2;

	return tree[node] = init(s,mid,node*2) * init(mid+1,e,node*2+1);

}

void update(int s, int e, int node, int idx, int k)
{
	if(idx < s || idx > e)
	{
		return;
	}

	tree[node] /= arr[idx];
	tree[node] *= k;

	if(s == e)
	{
		return;
	}

	int mid = (s+e)/2;
	update(s,mid,node*2,idx,k);
	update(mid+1,e,node*2+1,idx,k);

}

int multiple(int s, int e, int node, int l, int r)
{
	if(r < s || l > e)
	{
		return 1;
	}
	if(l <= s && r >= e)
	{
		return tree[node];
	}

	int mid = (s+e)/2;

	return multiple(s,mid,node*2,l,r)*multiple(mid+1,e,node*2+1,l,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>N>>K)
	{
		for(int i = 1;i<=N;++i)
		{
			cin>>arr[i];
			if(arr[i] > 0)
			{
				arr[i] = 1;
			}
			else if(arr[i] < 0)
			{
				arr[i] = -1;
			}
			else
			{
				arr[i] = 0;
			}
		}
		init(1,N,1);

		for(int k = 0;k<K;++k)
		{
			char c;
			int i,j;
			cin>>c>>i>>j;

			if(c == 'C')
			{	
				int temp = arr[i];
				if(j > 0)
				{
					j = 1;
				}
				else if(j < 0)
				{
					j = -1;
				}
				else
				{
					j = 0;
				}
				if(temp == 0)
				{
					arr[i] = j;
					init(1,N,1);
				}
				else
				{
					update(1,N,1,i,j);
					arr[i] = j;
				}
			}
			else
			{
				int res = multiple(1,N,1,i,j);
				if(res > 0)
				{
					cout<<'+';
				}
				else if(res < 0)
				{
					cout<<'-';
				}
				else
				{
					cout<<'0';
				}
			}
		}
		cout<<'\n';
	}


	return 0;
}

