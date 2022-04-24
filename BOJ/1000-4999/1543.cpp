#include <bits/stdc++.h>

// 1543 문서 검색

// update 220424

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

string s1,s2;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin,s1);
	getline(cin,s2);

	int j = 0;
	int temp = -1;

	for(int i = 0;i<s1.length();++i)
	{
		if(s1[i] == s2[j])
		{
			if(j == 0)
			{
				temp = i;
			}
			j++;
		}
		else
		{
			if(temp != -1)
			{
				i = temp;
				temp = -1;
			}
			j = 0;
		}
		if(j == s2.length())
		{
			result++;
			temp = i+1;
			j = 0;
		}
	}

	cout<<result;

	return 0;
}

