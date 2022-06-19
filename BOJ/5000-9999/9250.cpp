#include <bits/stdc++.h>

// 9250 문자열 집합 판정

// update 220619

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 205;
const int C_MAX = 26;

struct Trie
{
	Trie* go[C_MAX];
	Trie* fail {nullptr};
	bool output {false};

	Trie()
	{
		fill(go,go+C_MAX,nullptr);
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
			output = true;
			return;
		}
		int nextvalue = *str - 'a';
		if(!go[nextvalue])
		{
			go[nextvalue] = new Trie();
		}
		go[nextvalue]->insert(str+1);
	}
};

int N,M;
string s;
queue<Trie*> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie *root = new Trie();

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>s;
		root->insert(s.c_str());
	}

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
			{//if next is not exist, continue
				continue;
			}

			if(cur == root)
			{//root's fail is root
				next->fail = root;
			}
			else
			{
				Trie *dest = cur->fail;

				while(dest != root && !dest->go[i])	//fail을 참조할 가장 가까운 조상을 찾아감
				{//fail함수값이 root가 아니고, i인 다음 노드가 없으면
					dest = dest->fail;
				}
				if(dest->go[i])
				{//fail(px) = go(fail(p),x);  
					dest = dest->go[i];
				}
				next->fail = dest;
			}

			if(next->fail->output)
			{
				next->output = true;
			}
			Q.push(next);
		}
	}

	cin>>M;

	while(M--)
	{
		string str;
		Trie *cur = root;
		bool result = false;

		cin>>str;
		for(int i = 0;str[i];++i)
		{
			int nextval = str[i] - 'a';

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
				result = true;
				break;
			}
		}

		if(result)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}

	delete root;

	return 0;
}