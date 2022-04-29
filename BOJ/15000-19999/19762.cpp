#include <bits/stdc++.h>

// 19762 친구비

// update 220429

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 10001;
const int MOD = 1000000007;

int N,M,k;
int p[MAX];
int cost[MAX];
bool checkfriend[MAX];

int find(int a)
{
	if(p[a] < 0)
	{
		return a;
	}
	else
	{
		p[a] = find(p[a]);
		return p[a];
	}
}

void merge(int v, int w)
{
	v = find(v);
	w = find(w);

	if(v == w)
	{
		return;
	}

	if(cost[v] < cost[w])
	{
		p[w] = v;
	}
	else
	{
		p[v] = w;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>k;
	int result = 0;

	for(int i = 1;i<=N;++i)
	{
		cin>>cost[i];
		p[i] = -1;
		checkfriend[i] = false;
	}

	for(int i = 1;i<=M;++i)
	{
		int v,w;
		cin>>v>>w;

		merge(v,w);
	}

	for(int i = 1;i<=N;++i)
	{
		int now = find(i);
		if(checkfriend[now] == false)
		{
			checkfriend[now] = true;
			result += cost[now];
		}
	}

	if(k-result < 0)
	{
		cout<<"Oh no";
	}
	else
	{
		cout<<result;
	}


	return 0;
}

