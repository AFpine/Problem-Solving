#include <bits/stdc++.h>

// 5670 휴대폰 자판

// update 220614

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int TRIE_MAX = 26;

struct Trie
{
	Trie *next[TRIE_MAX];
	bool output = false;
	bool nextexist = false;
	int childnum = 0;

	Trie()
	{
		fill(next,next+TRIE_MAX,nullptr);
	}
	~Trie()
	{
		for(int i = 0;i<TRIE_MAX;++i)
		{
			if(next[i])
			{
				delete next[i];
			}
		}
	}

	void insert(const string &s, int idx, int len)
	{
		if(idx == len)
		{
			output = true;
		}
		else
		{
			int nextvalue = s[idx] - 'a';
			if(next[nextvalue] == nullptr)
			{
				next[nextvalue] = new Trie;
				childnum++;
			}
			nextexist = true;
			next[nextvalue]->insert(s,idx+1,len);
		}
	}

	int pushcnt(const string &s, int idx, int len, int ret)
	{
		if(idx == len)
		{
			return ret;
		}
		int nextvalue = s[idx] - 'a';
		if(idx == 0)
		{
			return next[nextvalue]->pushcnt(s,idx+1,len,ret+1);
		}
		else
		{
			if(childnum >= 2)
			{
				return next[nextvalue]->pushcnt(s,idx+1,len,ret+1);
			}
			else if(output == true)
			{
				return next[nextvalue]->pushcnt(s,idx+1,len,ret+1);
			}
			else
			{
				return next[nextvalue]->pushcnt(s,idx+1,len,ret);
			}
		}
	}
};

int N;
vector<string> dict;

void init()
{
	dict.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(2);

	while(cin>>N)
	{
		init();

		double result = 0;
		Trie* root = new Trie;

		for(int i = 1;i<=N;++i)
		{
			string s;
			cin>>s;
			dict.push_back(s);
			root->insert(s,0,s.length());
		}

		for(auto &s : dict)
		{
			result += root->pushcnt(s,0,s.length(),0);
		}

		cout<<result/N<<"\n";

		delete root;
	}
	

	return 0;
}


