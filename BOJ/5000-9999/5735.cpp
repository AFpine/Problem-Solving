#include <bits/stdc++.h>

// 5735 Emoticons :-)

// update 220619

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 205;
const int C_MAX = 128;


struct Trie
{
	Trie* go[C_MAX];
	Trie* fail {nullptr};
	int len {0};
	bool output {false};

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

	void insert(const char *str, int leng)
	{
		if(*str == '\0')
		{
			len = leng;
			output = true;
			return;
		}
		int nextvalue = *str;
		if(!go[nextvalue])
		{
			go[nextvalue] = new Trie();
		}
		go[nextvalue]->insert(str+1, leng);
	}
};

int N,M;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		cin>>N>>M;
		if(N == 0 && M == 0)
		{
			break;
		}

		Trie *root = new Trie();

		for(int i = 1;i<=N;++i)
		{
			cin>>s;
			root->insert(s.c_str(), s.length());
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
					next->output = true;
					next->len = next->fail->len;
				}
				Q.push(next);
			}
		}

		long long result = 0;

		getline(cin,s);
		while(M--)
		{
			vector<pair<int,int>> resultV;
			getline(cin,s);

			Trie *cur = root;
			for(int i = 0;s[i];++i)
			{
				int nextval = s[i];

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
					resultV.push_back({i-(cur->len)+1,i});
				}
			}

			int temp = -1;
			for(auto &p : resultV)
			{
				if(p.first <= temp)
				{
					continue;
				}
				temp = p.second;
				result++;
			}
		}


		cout<<result<<'\n';

		delete root;
	}

	return 0;
}