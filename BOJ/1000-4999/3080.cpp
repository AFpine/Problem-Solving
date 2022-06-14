#include <bits/stdc++.h>

// 3080 아름다운 이름

// update 220614

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int TRIE_MAX = 26;
const int MOD = 1e9+7;

long long result = 1;
long long fact[3001];

struct Trie
{
	vector<pair<char, Trie*>> next;
	bool output = false;
	int childnum = 0;

	void insert(const char *s)
	{
		if(!(*s))
		{
			output = true;
			return;
		}
		else
		{
			int nextvalue = *s - 'A';
			for(auto &p : next)
			{
				if(p.first == nextvalue)
				{
					p.second->insert(s+1);
					return;
				}
			}
			childnum++;
			next.push_back({nextvalue, new Trie});
			next.back().second->insert(s+1);
		}
	}

	void traverse()
	{
		if(childnum == 0)
		{
			return;
		}

		if(output && childnum >= 1)
		{
			result = (result*(fact[childnum+1])) % MOD;
		}
		else if(output == false && childnum >= 2)
		{
			result = (result*(fact[childnum])) % MOD;
		}

		for(auto &p : next)
		{
			p.second->traverse();
		}
	}
};

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie;
	
	cin>>N;
	for(int i = 1;i<=N;++i)
	{
		string s;
		cin>>s;
		root->insert(s.c_str());
	}

	fact[1] = 1;
	for(int i = 2;i<=N;++i)
	{
		fact[i] = (i*fact[i-1]) % MOD;
	}

	root->traverse();

	cout<<result;	

	return 0;
}


