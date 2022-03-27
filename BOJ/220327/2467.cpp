#include <bits/stdc++.h>

// 2467 Solution

// update 220327

using namespace std;

int solution[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int start,end;
	int resultl, resultr;
	int now;
	int comp = numeric_limits<int>::max();

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>solution[i];
	}

	start = 1;
	end = N;

	while(start<end)
	{
		if(abs(comp) > abs(solution[start] + solution[end]))
		{
			comp = solution[start] + solution[end];
			resultl = start;
			resultr = end;
 		}
		if(comp == 0)
		{
			break;
		}
		if(solution[start] + solution[end] > 0)
		{
			end--;
		}
		else
		{
			start++;
		}
	}

	cout<<solution[resultl]<<" "<<solution[resultr]<<'\n';

	return 0;	
}