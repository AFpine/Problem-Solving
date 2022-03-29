#include <bits/stdc++.h>

// 9252 LCS2 (Dynamic Programming)

// update 220328

using namespace std;

int LCS[1001][1001];
bool check[1001][1001];
pair<int,int> pre[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1,s2;
	int len1,len2;
	stack<char> stack;

	cin>>s1>>s2;

	len1 = s1.length();
	len2 = s2.length();

	for(int i = 0;i<len1;++i)
	{
		for(int j = 0;j<len2;++j)
		{
			pre[i+1][j+1] = {0,0};
			if(s1[i] == s2[j])
			{
				LCS[i+1][j+1] = LCS[i][j] + 1;
				check[i+1][j+1] = true;
				pre[i+1][j+1] = {i,j};
			}
			else
			{
				if(LCS[i+1][j] > LCS[i][j+1])
				{
					LCS[i+1][j+1] = LCS[i+1][j];
					pre[i+1][j+1] = {i+1,j};
				}
				else
				{
					LCS[i+1][j+1] = LCS[i][j+1];
					pre[i+1][j+1] = {i,j+1};
				}
			}
		}
	}

	if(LCS[len1][len2] == 0)
	{
		cout<<"0";
	}
	else
	{
		pair<int,int> temp = {len1,len2};
		cout<<LCS[len1][len2]<<'\n';
		while(temp != pair<int,int>(0,0))
		{
			if(check[temp.first][temp.second] == true)
			{
				stack.push(s1[temp.first-1]);
			}
			temp = pre[temp.first][temp.second];
		}
		while(!stack.empty())
		{
			cout<<stack.top();
			stack.pop();
		}
	}




	return 0;	
}