#include <bits/stdc++.h>

// 3136 평면도

// update 220627

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int MOD = 1e9+7;

int N;
string s;
//set을 써서 중복되는 정점과 간선을 처리해준다
set<pii> node;
set<pair<pii,pii>> edge;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	cin>>s;

	node.insert({0,0});
	pii cur = {0,0};
	pii prv;
	for(int i = 0;i<N;++i)
	{
		int op = s[i]-'0';
		for(int j = 0;j<2;++j)
		{
			int x = cur.first + dx[op];
			int y = cur.second + dy[op];
			prv = cur;
			cur = {x,y};
			node.insert(cur);
			//같은 두 정점을 잇는 간선은 단방향만 처리해준다
			edge.insert({min(prv,cur), max(prv,cur)});
		}
	}

	cout<<1+edge.size()-node.size();

	return 0;
}

