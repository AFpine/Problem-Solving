#include <bits/stdc++.h>

// 3392 화성 지도

// update 220609

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 30005;
const int MOD = 1e9+7;

struct Line
{
	int x, y1, y2;
	bool start;
};

int N;
vector<Line> line;
long long result;
long long tree[4*MAX];
long long cnt[4*MAX];

void update(int s, int e, int node, int l, int r, long long k)
{
	if(l > e || r < s)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		cnt[node] += k;
	}
	else
	{
		int mid = (s+e)/2;
		update(s,mid,node*2,l,r,k);
		update(mid+1,e,node*2+1,l,r,k);
	}

	if(cnt[node])
	{
		tree[node] = e-s+1;
	}
	else
	{
		if(s == e)
		{
			tree[node] = 0;
		}
		else
		{
			tree[node] = tree[node*2] + tree[node*2+1];
		}
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
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;

		line.push_back({x1,y1,y2-1,true});
		line.push_back({x2,y1,y2-1,false});
	}

	sort(line.begin(),line.end(),[](Line &a, Line &b)
	{
		return a.x < b.x;
	});

	int prev = -1;
	for(auto &l : line)
	{
		if(prev != -1)
		{
			result += tree[1] * (l.x - prev);
		}

		if(l.start)
		{
			update(0,30000,1,l.y1,l.y2,1);
		}
		else
		{
			update(0,30000,1,l.y1,l.y2,-1);
		}

		prev = l.x;
	}

	cout<<result;

	return 0;
}


