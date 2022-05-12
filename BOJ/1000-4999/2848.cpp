#include <bits/stdc++.h>

// 2848 알고스팟어

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

int N;
int alpcnt = 0;
bool usedalp[27];
string words[101];
bool adj[27][27];
int indegree[27];
bool incorrect,indirect;
queue<int> Q;
string result;

void stringCompare(string &s1, string &s2)
{
	int len1 = s1.length();
	int len2 = s2.length();

	if(len1 <= len2)
	{
		for(int i = 0;i<len1;++i)
		{
			if(s1[i] != s2[i])
			{
				if(adj[s1[i]-'a'][s2[i]-'a'] == false)
				{
					indegree[s2[i]-'a']++;
				}
				adj[s1[i]-'a'][s2[i]-'a'] = true;
				return;
			}
		}
	}
	else
	{
		for(int i = 0;i<len2;++i)
		{
			if(s1[i] != s2[i])
			{
				if(adj[s1[i]-'a'][s2[i]-'a'] == false)
				{
					indegree[s2[i]-'a']++;
				}
				adj[s1[i]-'a'][s2[i]-'a'] = true;
				return;
			}
		}
		incorrect = true;
		return;
	}
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>words[i];
		for(int j = 0;j<words[i].length();++j)
		{
			usedalp[words[i][j]-'a'] = true;
		}
	}
	for(int i = 0;i<=26;++i)
	{
		if(usedalp[i] == true)
		{
			indegree[i] = 0;
			alpcnt++;
		}
		else
		{
			indegree[i] = INF;
		}
	}
	for(int i = 1;i<=N;++i)
	{
		for(int j = i+1;j<=N;++j)
		{
			stringCompare(words[i],words[j]);
		}
	}

	for(int i = 0;i<=26;++i)
	{
		if(indegree[i] == 0)
		{
			Q.push(i);
		}
	}

	for(int i = 1;i<=alpcnt;++i)
	{
		if(Q.empty())
		{
			incorrect = true;
			break;
		}
		int cur = Q.front();
		Q.pop();
		if(!Q.empty())
		{
			indirect = true;
			break;
		}
		result += (char)(cur+'a');

		for(int j = 0;j<=26;++j)
		{
			if(adj[cur][j] == true)
			{
				if(--indegree[j] == 0)
				{
					Q.push(j);
				}
			}
		}
	}

	if(incorrect)
	{
		cout<<"!";
	}
	else if(indirect)
	{
		cout<<"?";
	}
	else
	{
		cout<<result;
	}
	


	return 0;
}
