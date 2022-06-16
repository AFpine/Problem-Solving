#include <bits/stdc++.h>

// 5446 용량 부족

// update 220615

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2005;
const int CHARMAX = 65;
const int CAPALPS = 26;
const int NUMBERS = 52;
const int DOT = 62;

int convert(const char &c)
{
	if(c >= 'a' && c <= 'z')
	{
		return c-'a';
	}
	else if(c >= 'A' && c <= 'Z')
	{
		return c-'A'+CAPALPS;
	}
	else if(c >= '0' && c <= '9')
	{
		return c-'0'+NUMBERS;
	}
	else
	{
		return DOT;
	}
}

struct Trie
{
	Trie* next[CHARMAX] = {nullptr};
	bool end = false;
	bool notErase = false;
	int Erase = 0;

	Trie()
	{
		fill(next,next+CHARMAX,nullptr);
	}
	~Trie()
	{
		for(int i = 0;i<CHARMAX;++i)
		{
			if(next[i])
			{
				delete next[i];
			}
		}
	}

	void insert(const char *str, bool noterase)
	{
		if(*str == '\0')
		{
			if(noterase)
			{
				notErase = true;
			}
			else
			{
				end = true;
			}
		}
		else
		{
			int nextchar = convert((*str));
			if(next[nextchar] == nullptr)
			{
				next[nextchar] = new Trie();
			}
			if(noterase == false)
			{
				Erase++;
			}
			else
			{
				notErase = true;
			}
			next[nextchar]->insert(str+1, noterase);
		}
	}
};

int T;
int N,M;
int result;

void dfs(const Trie *T)
{
	if(T->Erase == 0)
	{
		if(T->end == true)
		{
			result++;
		}
		return;
	}
	if(T->notErase == false)
	{
		result++;
		return;
	}
	if(T->notErase == true && T->end == true)
	{
		result++;
	}
	for(int i = 0;i<CHARMAX;++i)
	{
		if(T->next[i])
		{
			dfs(T->next[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		result = 0;

		Trie *root = new Trie();
		
		cin>>N;
		string s;
		for(int i = 0;i<N;++i)
		{
			cin>>s;
			root->insert(s.c_str(), false);
		}
		cin>>M;
		for(int i = 0;i<M;++i)
		{
			cin>>s;
			root->insert(s.c_str(), true);
		}

		dfs(root);

		cout<<result<<'\n';

		delete root;
	}


	return 0;
}