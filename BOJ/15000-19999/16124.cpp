#include <bits/stdc++.h>

// 16124 나는 행복합니다

// update 220621

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const long long MOD = 998244353;

int N,Q;
string S;
//pw[i] : 10^i
int pw[MAX];
int tree[4*MAX][10];
int lazy[4*MAX][10];
int temp[10];

void propagate(int s, int e, int node)
{
	bool flag = true;
	for(int i = 0;i<10;++i)
	{
		if(lazy[node][i] != i)
		{//lazy에 갱신 되어야 하는 값이 들어있으면
			flag = false;
		}
	}
	if(flag)
	{
		return;
	}

	memset(temp,0,sizeof(temp));
	//tree의 값을 lazy에 따라 변경
	for(int i = 0;i<10;++i)
	{//현재 node에서 i의 갯수가 lazy[node][i]의 갯수에 추가될 것
		temp[lazy[node][i]] = (temp[lazy[node][i]] + tree[node][i]) % MOD;
	}
	for(int i = 0;i<10;++i)
	{//tree에 대입
		tree[node][i] = temp[i];
	}

	if(s != e)
	{//현재 node가 leaf가 아니면 (lazy를 갱신해줘야 할 자식 node가 존재하면)
		for(int i = 0;i<10;++i)
		{//lazy[자식node][i] : 현재 node의 i에서 갱신된 어떤 값(수)
			lazy[node*2][i] = lazy[node][lazy[node*2][i]];
			lazy[node*2+1][i] = lazy[node][lazy[node*2+1][i]];
		}
	}

	for(int i = 0;i<10;++i)
	{//lazy의 default로 초기화
		lazy[node][i] = i;
	}
}

void update(int s, int e, int node, int l, int r, int a, int b)
{
	propagate(s,e,node);
	if(r < s || l > e)
	{
		return;
	}
	if(l <= s && r >= e)
	{
		lazy[node][a] = b;
		propagate(s,e,node);
		return;
	}
	int mid = (s+e)/2;
	update(s,mid,node*2,l,r,a,b);
	update(mid+1,e,node*2+1,l,r,a,b);
	for(int i = 0;i<10;++i)
	{
		tree[node][i] = ((long long)pw[e-mid]*tree[node*2][i] + tree[node*2+1][i]) % MOD;
	}
}

int query(int s, int e, int node, int l, int r)
{
	propagate(s,e,node);
	if(r < s || l > e)
	{
		return 0;
	}
	if(l <= s && r >= e)
	{
		long long ret = 0;
		for(int i = 0;i<10;++i)
		{
			ret = (ret + (long long)tree[node][i]*i) % MOD;
		}
		return ret;
	}
	int mid = (s+e)/2;
	long long ret = 0;
	if(mid+1 <= r)
	{
		ret = ((long long)pw[min(e,r)-mid]*query(s,mid,node*2,l,r) + query(mid+1,e,node*2+1,l,r));
	}
	else
	{// mid + 1 > r
		ret = query(s,mid,node*2,l,r);
	}
	return ret % MOD;
}

void init(int s, int e, int node)
{
	for(int i = 0;i<10;++i)
	{
		lazy[node][i] = i;
		//tree[node] 에서 i가 i로 바뀌어야 함 : 초기값
		//원래 알던 lazy[node] = 0 과 같은 것
	}
	if(s == e)
	{
		tree[node][S[s-1]-'0'] = 1;
		return;
	}
	int mid = (s+e)/2;
	init(s,mid,node*2);
	init(mid+1,e,node*2+1);
	for(int i = 0;i<10;++i)
	{
		tree[node][i] = ((long long)pw[e-mid] * tree[node*2][i] + tree[node*2+1][i]) % MOD;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pw[0] = 1;
	for(int i = 1;i<MAX;++i)
	{
		pw[i] = (long long)pw[i-1]*10 % MOD;
	}

	cin>>S;
	N = S.length();
	init(1,N,1);
	cin>>Q;
	while(Q--)
	{
		int op;
		cin>>op;
		if(op == 1)
		{
			int i, j, f, t;
			cin>>i>>j>>f>>t;
			update(1,N,1,i,j,f,t);
		}
		else
		{
			int i,j;
			cin>>i>>j;
			cout<<query(1,N,1,i,j)<<'\n';
		}
	}



	return 0;
}