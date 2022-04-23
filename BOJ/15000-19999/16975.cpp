#include <bits/stdc++.h>

// 16975 수열과 쿼리 21 (Fenwick tree, Lazy propagation)

// update 220422

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M,K;
int qn;
int a,b,c,d;
long long arr[1000001];
long long tree[1000001];


void update(int idx, long long diff)
{
	while(idx <= N)
	{
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

long long sum(int idx)
{
	long long result = 0;
	while(idx > 0)
	{
		result += tree[idx];
		idx -= (idx & -idx);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	cin>>arr[1];
	update(1,arr[1]);
	for(int i = 2;i<=N;++i)
	{
		cin>>arr[i];
		update(i,arr[i]-arr[i-1]);
	}

	cin>>qn;

	while(qn--)
	{
		cin>>a;
		if(a == 1)
		{
			cin>>b>>c>>d;
			update(b,d);
			update(c+1,-d);
		}
		else
		{
			cin>>b;
			cout<<sum(b)<<'\n';
		}
	}


	return 0;
}

