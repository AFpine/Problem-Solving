#include <bits/stdc++.h>

// 10256 돌연변이

// update 220619

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 205;
const int C_MAX = 4;

struct Trie
{
	Trie* go[C_MAX];
	Trie* fail {nullptr};
	int output {0};

	Trie()
	{
		fill(go,go+C_MAX,nullptr);
		output = 0;
	}
	~Trie()
	{
		for(int i = 0;i<C_MAX;++i)
		{
			if(go[i])
			{
				delete go[i];
			}
		}
	}

	void insert(const char *str)
	{
		if(*str == '\0')
		{
			output = 1;
			return;
		}
		int nextvalue;
		if(*str == 'A')
		{
			nextvalue = 0;
		}
		else if(*str == 'C')
		{
			nextvalue = 1;
		}
		else if(*str == 'G')
		{
			nextvalue = 2;
		}
		else
		{
			nextvalue = 3;
		}
		if(!go[nextvalue])
		{
			go[nextvalue] = new Trie();
		}
		go[nextvalue]->insert(str+1);
	}
};

int T;
int N,M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		string DNA, marker;
		cin>>N>>M;
		cin>>DNA>>marker;

		Trie *root = new Trie();

		root->insert(marker.c_str());
		
		for(int i = 0;i<=M;++i)
		{
			for(int j = i + 2; j <= M; ++j)
			{
				reverse(marker.begin()+i, marker.begin()+j);
				root->insert(marker.c_str());
				reverse(marker.begin()+i, marker.begin()+j);
			}
		}

		queue<Trie*> Q;
		root->fail = root;
		Q.push(root);

		while(!Q.empty())
		{
			Trie *cur = Q.front();
			Q.pop();

			for(int i = 0;i<C_MAX;++i)
			{
				Trie *next = cur->go[i];
				if(!next)
				{
					continue;
				}

				if(cur == root)
				{
					next->fail = root;
				}
				else
				{
					Trie *dest = cur->fail;
					while(dest != root && !dest->go[i])
					{
						dest = dest->fail;
					}
					if(dest->go[i])
					{
						dest = dest->go[i];
					}
					next->fail = dest;
				}
				if(next->fail->output)
				{
					next->output = next->fail->output;
				}

				Q.push(next);
			}
		}

		long long result = 0;
		Trie *cur = root;

		for(int i = 0;DNA[i];++i)
		{
			int nextval;
			if(DNA[i] == 'A')
			{
				nextval = 0;
			}
			else if(DNA[i] == 'C')
			{
				nextval = 1;
			}
			else if(DNA[i] == 'G')
			{
				nextval = 2;
			}
			else
			{
				nextval = 3;
			}
			while(cur != root && !cur->go[nextval])
			{
				cur = cur->fail;
			}
			if(cur->go[nextval])
			{
				cur = cur->go[nextval];
			}
			if(cur->output)
			{
				result++;
			}

		}

		cout<<result<<'\n';

		delete root;
	}

	return 0;
}