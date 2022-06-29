#include <bits/stdc++.h>

// 2809 아스키 거리

// update 220628

using namespace std;
typedef long long ll;
typedef pair<double,double> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 300005;
const long long MOD = 1e9+7;


//이딴걸로 메모리 아껴야하는 쓰레기 문제 

int isexist(int &exist, int ch)
{
	return (exist & (1<<(25-ch)));
}

int chidx(int &exist, int ch)
{
	int cnt = 0;
	for(int i = 0;i<ch;++i)
	{
		if(exist & (1<<(25-i)))
		{
			cnt++;
		}
	}
	return cnt;
}

int nthch(int &exist, int n)
{
	int cnt = 0;
	for(int i = 0;i<26;++i)
	{
		if(exist & (1<<(25-i)))
		{
			if(cnt == n)
			{
				return i;
			}
			cnt++;
		}
	}
	return -1;
}

struct Trie
{
	int output = 0;
	int exist = 0;
	Trie *fail {nullptr};
	vector<Trie*> child;

	Trie()
	{
		fail = nullptr;
		output = exist = 0;
	}
	~Trie()
	{
		for(int i = 0;i<child.size();++i)
		{
			delete child[i];
		}
	}

	void insert(string P, int k)
	{
		Trie* now = this;

		for(int i = 0;i<P.length();++i)
		{
			int cur = P[i]-'a';
			int n = chidx(now->exist,cur);
			if(!isexist(now->exist,cur))
			{
				now->exist |= (1<<(25-cur));
				now->child.insert(now->child.begin() + n, new Trie());
			}
			now = now->child[n];
		}
		if(now->output < k)
		{
			now->output = k;
		}
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
			
			for(int i = 0;i<cur->child.size();++i)
			{
				Trie* next = cur->child[i];
				//현재 노드가 루트면, 자식의 fail은 루트다
				if(cur == root)
				{
					next->fail = root;
				}
				else//현재 노드가 루트가 아니면
				{
					//prv : 현재 노드의 fail(NULL이 아님)
					int ch = nthch(cur->exist, i);
					Trie* prv = cur->fail;
					while(prv != root && !isexist(prv->exist,ch))
					{
						prv = prv->fail;
					}
					if(isexist(prv->exist,ch))
					{
						prv = prv->child[chidx(prv->exist,ch)];
					}
					next->fail = prv;
				}
				if(next->fail->output)
				{
					if(next->fail->output > next->output)
					{
						next->output = next->fail->output;
					}
				}
				//현재 노드의 자식들을 Q에 넣는다
				//자식들의 fail은 다 정해졌다
				Q.push(next);
			}
		}
	}
};

int N,M;
bool matched[MAX];
int mark[MAX], chk[MAX];

int matching(string &S, Trie* root)
{
	Trie* now = root;
	for(int i = 0;S[i];++i)
	{
		int next = S[i] - 'a';
		while(now != root && !isexist(now->exist, next))
		{
			now = now->fail;
		}
		if(isexist(now->exist, next))
		{
			now = now->child[chidx(now->exist,next)];
		}
		if(now->output)
		{
			mark[i] = max(mark[i], now->output);
			for(int j = i-mark[i]+1; j<=i;++j)
			{
				matched[j] = true;
			}
		}
	}

	int result = 0;

	for(int i = 0;i<N;++i)
	{
		if(!matched[i])
		{
			result++;
		}
	}

	return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;

	Trie* root = new Trie();

	cin>>N;
	cin>>S;

	cin>>M;
	for(int i = 0;i<M;++i)
	{
		string temp;
		cin>>temp;
		if(temp.length() > N)
		{
			continue;
		}
		root->insert(temp,temp.length());
	}

	root->getFail();

	cout<<matching(S,root);

	return 0;
}