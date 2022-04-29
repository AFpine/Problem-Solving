#include <bits/stdc++.h>

// 4195 친구 네트워크

// update 220429

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 100001;
const int MOD = 1000000007;

int T,F;
int p[MAX*3];

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

	p[v] += p[w];
	p[w] = v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;

	while(T--)
	{
		unordered_map<string,int> friends;
		string s1,s2;
		int idx = 0;

		cin>>F;

		for(int i = 1;i<=F;++i)
		{
			cin>>s1>>s2;
			if(friends.find(s1) == friends.end())
			{
				friends.insert({s1,idx});
				p[idx] = -1;
				idx++;
			}
			if(friends.find(s2) == friends.end())
			{
				friends.insert({s2,idx});
				p[idx] = -1;
				idx++;
			}
			merge(friends[s1], friends[s2]);

			cout<<abs(p[find(friends[s1])])<<'\n';
		}
	}

	return 0;
}

