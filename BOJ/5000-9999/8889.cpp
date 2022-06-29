#include <bits/stdc++.h>

// 8889 등고선 지도

// update 220627

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2000005;
const int MOD = 1e9+7;

struct L
{
	int x, y1, y2, state;
};

int T,M;
int pos[20005][105][2];
int K[20005];
int tree[4*MAX], lazy[4*MAX];
vector<L> line;

void propagate(int s, int e, int node)
{
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(s != e)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, int val)
{
	propagate(s,e,node);

	if(l > e || r < s)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node] += val;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;
	update(s,mid,node*2,l,r,val);
	update(mid+1,e,node*2+1,l,r,val);
	
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int s, int e, int node, int l, int r)
{
	propagate(s,e,node);

	if(l > e || r < s)
	{
		return 0;
	}
	if(l <= s && r >= e)
	{
		return tree[node];
	}

	int mid = (s+e)/2;

	return max(query(s,mid,node*2,l,r), query(mid+1,e,node*2+1,l,r));
}

void solve()
{
	sort(line.begin(),line.end(),[] (L a, L b)
	{
		return make_tuple(a.x,a.state,a.y1,a.y2) < make_tuple(b.x,b.state,b.y1,b.y2);
	});
	int result = 0;
	for(int i = 0;i<line.size();++i)
	{
		update(1,2000000,1,line[i].y2, line[i].y1, line[i].state);
		result = max(result,query(1,2000000,1,1,2000000));
	}
	cout<<result<<'\n';
}

void input()
{
	cin>>M;
	for(int i = 0;i<M;++i)
	{
		cin>>K[i];
		for(int j = 0;j<K[i];++j)
		{
			cin>>pos[i][j][0]>>pos[i][j][1];
		}
	}

	vector<int> temp;
	for(int i = 0;i<M;++i)
	{
		for(int j = 0;j<K[i];++j)
		{
			temp.push_back(pos[i][j][0]);
		}
	}
	sort(temp.begin(),temp.end());
	temp.erase(unique(temp.begin(),temp.end()),temp.end());
	for(int i = 0;i<M;++i)
	{
		for(int j = 0;j<K[i];++j)
		{
			pos[i][j][0] = lower_bound(temp.begin(), temp.end(),pos[i][j][0]) - temp.begin();
		}
	}

	temp.clear();
	for(int i = 0;i<M;++i)
	{
		for(int j = 0;j<K[i];++j)
		{
			temp.push_back(pos[i][j][1]);
		}
	}
	sort(temp.begin(),temp.end());
	temp.erase(unique(temp.begin(),temp.end()),temp.end());
	for(int i = 0;i<M;++i)
	{
		for(int j = 0;j<K[i];++j)
		{
			pos[i][j][1] = lower_bound(temp.begin(), temp.end(),pos[i][j][1]) - temp.begin();
		}
	}
	//여기까지 x,y 값 모두 압축 완료

	for(int i = 0;i<M;++i)
	{
		for(int j = 0;j<K[i];++j)
		{
			if(pos[i][j][0] == pos[i][(j+1)%K[i]][0])
			{
				if(pos[i][j][1] > pos[i][(j+1)%K[i]][1])
				{//증가 간선
					line.push_back({pos[i][j][0]+1, pos[i][j][1]+1, pos[i][(j+1)%K[i]][1]+2, 1});
				}
				else
				{//감소 간선
					line.push_back({pos[i][j][0]+1, pos[i][(j+1)%K[i]][1]+1, pos[i][j][1]+2, -1});
				}
			}
		}
	}
}

void init()
{
	line.clear();
	fill(lazy,lazy+4*MAX,0);
	fill(tree,tree+4*MAX,0);
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
		input();
		solve();
	}

	return 0;
}

