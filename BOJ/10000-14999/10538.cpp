#include <bits/stdc++.h>

// 10538 빅 픽쳐

// update 220628

using namespace std;
typedef long long ll;
typedef pair<double,double> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+7;

struct Trie
{
	int end = -1;
	Trie *fail {nullptr};
	map<char,Trie*> child;

	void insert(string P, int k)
	{
		Trie* now = this;

		for(int i = 0;i<P.length();++i)
		{
			if(now->child.find(P[i]) == now->child.end())
			{
				now->child[P[i]] = new Trie();
			}
			now = now->child[P[i]];
		}
		now->end = k;
	}

	void getFail()
	{
		Trie* root = this;
		queue<Trie*> Q;
		root->fail = root;
		Q.push(root);

		while(!Q.empty())
		{
			//처음 시작할 때, root의 fail은 root라고 정해놓음
			//이 Q에 들어올 때 cur의 fail은 정해져 있는 상태에서 들어옴
			//fail을 설정할 때, 자신보다 낮은 레벨에 있는 fail값은
			//다 정해져 있어야 dp가 가능하기 때문
			auto cur = Q.front();
			Q.pop();
			
			for(auto &ch : cur->child)
			{
				Trie* next = ch.second;
				
				//현재 노드가 루트면, 자식의 fail은 루트다
				if(cur == root)
				{
					next->fail = root;
				}
				else//현재 노드가 루트가 아니면
				{
					//prv : 현재 노드의 fail(NULL이 아님)
					Trie* prv = cur->fail;
					while(prv != root && prv->child.find(ch.first) == prv->child.end())
					{
						prv = prv->fail;
					}
					if(prv->child.find(ch.first) != prv->child.end())
					{
						prv = prv->child[ch.first];
					}
					next->fail = prv;
				}
				if(next->fail->end != -1)
				{
					next->end = next->fail->end;
				}
				//현재 노드의 자식들을 Q에 넣는다
				//자식들의 fail은 다 정해졌다
				Q.push(next);
			}
		}
	}
};

map<string,int> patternM;
int knum[2005];
string P[2005];
string M[2005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie();
	int w1,h1,w2,h2;

	cin>>h1>>w1>>h2>>w2;

	//패턴의 한 줄 씩 Trie에 입력
	for(int i = 0;i<h1;++i)
	{
		cin>>P[i];
		if(patternM.find(P[i]) == patternM.end())
		{
			patternM[P[i]] = i;
			knum[i] = i;
			root->insert(P[i],i);
		}
		else
		{
			knum[i] = patternM[P[i]];
		}
	}

	root->getFail();

	for(int i = 0;i<h2;++i)
	{
		cin>>M[i];
	}

	//걸작의 한 행마다 아호코라식의 매칭을 이용해서, 일치하는 패턴이 있으면 그 패턴의 번호를 check 배열에 넣는다
	vector<vector<int>> check(h2,vector<int>(w2,-1));
	for(int i = 0;i<h2;++i)
	{
		Trie* cur = root;
		for(int j = 0;j<w2;++j)
		{
			char next = M[i][j];
			while(cur != root && cur->child.find(next) == cur->child.end())
			{
				cur = cur->fail;
			}
			if(cur->child.find(next) != cur->child.end())
			{
				cur = cur->child[next];
			}
			if(cur->end != -1)
			{
				check[i][j] = cur->end;
			}
		}
	}

	//패턴들의 번호(중복처리를 한)를 다시 하나의 패턴 문자열로 보고 실패함수(pi)를 구함
	vector<int> pi(h1,0);
	int w = 0;
	for(int i = 1;i<h1;++i)
	{
		while(w > 0 && knum[i] != knum[w])
		{
			w = pi[w-1];
		}
		if(knum[i] == knum[w])
		{
			pi[i] = ++w;
		}
	}

	//걸작을 행으로 보는것이 아닌 열로 보면서 패턴과 일치하는 만큼 result를 증가한다
	int result = 0;
	for(int j = 0;j<w2;++j)
	{
		w = 0;
		for(int i = 0;i<h2;++i)
		{
			while(w > 0 && check[i][j] != knum[w])
			{
				w = pi[w-1];
			}
			if(check[i][j] == knum[w])
			{
				if(w == h1-1)
				{
					result++;
					w = pi[w];
				}
				else
				{
					w++;
				}
			}
		}
	}

	cout<<result;

	return 0;
}