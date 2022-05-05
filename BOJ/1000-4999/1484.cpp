#include <bits/stdc++.h>

// 1484 다이어트

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int G;
long long og, cur;
vector<int> res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>G;
	og = cur = 1;

	while(og <= cur)
	{
		if((cur == (og+1)) && (pow(cur,2)-pow(og,2) > G))
		{
			break;
		}
		if(pow(cur,2) - pow(og,2) == G)
		{
			res.push_back(cur);
		}

		if(pow(cur,2) - pow(og,2) >= G)
		{
			og++;
		}
		else
		{
			cur++;
		}
	}
	
	sort(res.begin(),res.end());

	if(res.empty())
	{
		cout<<"-1";
		return 0;
	}
	for(auto x : res)
	{
		cout<<x<<'\n';
	}

	return 0;
}

