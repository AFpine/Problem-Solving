#include <bits/stdc++.h>

// 5052 전화번호 목록

// update 220614

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 105;
const int TRIE_MAX = 10;

struct Trie
{
	Trie *next[TRIE_MAX];
	bool output = false;
	bool nextexist = false;

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

	void insert(const char* key)
	{
		if(*key == '\0')
		{
			output = true;
		}
		else
		{
			int nextvalue = *key - '0';
			if(next[nextvalue] == nullptr)
			{
				next[nextvalue] = new Trie;
			}
			nextexist = true;
			next[nextvalue]->insert(key+1);
		}
	}

	bool consistent()
	{
		if(nextexist && output)
		{
			return false;
		}
		for(int i = 0;i<TRIE_MAX;++i)
		{
			if(next[i] && (next[i]->consistent() == false))
			{
				return false;
			}
		}
		return true;
	}
};

int T;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		cin>>N;
		Trie *root = new Trie;

		for(int i = 0;i<N;++i)
		{
			char temp[11];
			cin>>temp;
			root->insert(temp);
		}

		if(root->consistent())
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}

	return 0;
}


