#include <bits/stdc++.h>

// 1167 Diameter of tree (DFS, DIameter of tree proof)

// update 220313

using namespace std;

int diameter = 0;
bool visited[100001];
int far = 1;

struct Node
{
	vector<pair<int,int>> edge;
};

void DFS(vector<Node>& v,int now, int nowdia)
{
	if(diameter < nowdia)
	{
		diameter = nowdia;
		far = now;
	}
	for(auto x : v[now].edge)
	{
		if(visited[x.first] == false)
		{
			visited[x.first] = true;
			DFS(v,x.first,nowdia+x.second);
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
	vector<Node> tree(100001);

	for(int i = 1;i<=n;++i)
	{
		cin>>a;
		while(1)
		{
			cin>>b;
			if(b == -1)
			{
				break;
			}
			cin>>c;
			tree[a].edge.push_back({b,c});
		}
	}

	visited[1] = true;
	DFS(tree,1,0);
	for(int j = 1;j<=n;++j)
	{
		visited[j] = false;
	}
	visited[far] = true;
	DFS(tree,far,0);
	for(int j = 1;j<=n;++j)
	{
		visited[j] = false;
	}
	visited[far] = true;
	DFS(tree,far,0);

	cout<<diameter<<"\n";
}