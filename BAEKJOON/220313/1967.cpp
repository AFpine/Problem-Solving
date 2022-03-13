#include <bits/stdc++.h>

// Diameter of tree (DFS)

// update 220313

using namespace std;

int diameter = 0;

struct Node
{
	vector<pair<int,int>> edge;
};

void DFS(vector<Node>& v, int parent, int now, int nowdia)
{
	diameter = max(diameter,nowdia);
	for(auto x : v[now].edge)
	{
		if(x.first != parent)
		{
			DFS(v,now,x.first,nowdia+x.second);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int a,b,c;
	cin>>n;
	vector<Node> tree(10001);

	for(int i = 1;i<n;++i)
	{
		cin>>a>>b>>c;
		tree[a].edge.push_back({b,c});
		tree[b].edge.push_back({a,c});
	}

	for(int i = 1;i<=n;++i)
	{
		DFS(tree,0,i,0);
	}
	cout<<diameter<<"\n";
}