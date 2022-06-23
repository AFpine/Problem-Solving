#include <bits/stdc++.h>

// 3172 현주와 윤주의 재미있는 단어 게임

// update 220623

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int N;
pair<string, int> words[MAX];
ll tree[4*MAX];

bool compare(const pair<string,int> &a, const pair<string,int> &b)
{
	int len = min(a.first.length(), b.first.length());
	for(int i = 0;i<len;++i)
	{
		if(a.first[i] != b.first[i])
		{
			return a.first[i] < b.first[i];
		}
	}
	return a.first.length() < b.first.length();
}

void update(int s, int e, int node, int pos, int val)
{
	if(s > pos || e < pos)
	{
		return;
	}
	if(s == e)
	{
		tree[node] = val;
		return;
	}
	int mid = (s+e) >> 1;
	update(s,mid,node*2,pos,val);
	update(mid+1,e,node*2+1,pos,val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int l, int r)
{
	if(l > e || r < s)
	{
		return 0;
	}
	if(l <= s && r >= e)
	{
		return tree[node];
	}
	int mid = (s+e) >> 1;
	return query(s,mid,node*2,l,r) + query(mid+1,e,node*2+1,l,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		string s;
		cin>>s;
		words[i] = {s,i};
	}

	sort(words+1, words+1+N, compare);

	//문자열 정렬 후, [1,N] 까지 순서대로 번호를 매김
	for(int i = 1;i<=N;++i)
	{
		reverse(words[i].first.begin(), words[i].first.end());
		words[i].second = i;
	}

	//문자열을 뒤집고 정렬 함
	sort(words+1, words+1+N, compare);

	//result : 뒤집기 전의 순서와 뒤집고 난 뒤의 순서의 상하 관계가 달라진 수
	ll result = 0;
	for(int i = 1;i<=N;++i)
	{
		//query : 현재 문자열의 뒤집기 전의 순서 보다 뒤에 였던 문자열이 
		//더 앞의 순서로 온 경우의 갯수
		result += query(1,N,1,words[i].second,N);
		//words[i].second 순서를 가진 문자열이 등장 
		update(1,N,1,words[i].second,1);
	}

	cout<<result;

	return 0;
}