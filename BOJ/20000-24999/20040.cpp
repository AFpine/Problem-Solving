#include <bits/stdc++.h>

// 20040 Cycle game (Union-find)

// update 220330

using namespace std;

struct UFset
{
	int head;
};

UFset ufset[500001];

int Find(int i)
{
	if(ufset[i].head == i)
	{
		return i;
	}
	else
	{
		return ufset[i].head = Find(ufset[i].head);
	}
}

void Union(int a, int b)
{
	ufset[Find(a)].head = Find(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	int a,b;
	int turn = -1;

	cin>>n>>m;

	for(int i = 0;i<n;++i)
	{
		ufset[i].head = i;
	}

	for(int i = 0;i<m;++i)
	{
		cin>>a>>b;
		if(Find(a) == Find(b))
		{
			turn = i+1;
			break;
		}
		Union(a,b);
	}

	if(turn == -1)
	{
		cout<<"0\n";
	}
	else
	{
		cout<<turn<<'\n';
	}

	return 0;
}