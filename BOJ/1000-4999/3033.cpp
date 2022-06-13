#include <bits/stdc++.h>

// 3033 가장 긴 문자열

// update 220613

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;

vector<int> pos[100010];

int MOD(long long a)
{
	if(a >= 0)
	{
		return a % 100005;
	}
	else
	{
		return -(-a % 100005) + 100005;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L;
	int result = 0;
	string S;

	cin>>L;
	cin>>S;

	int l = 0, r = L;
	while(l + 1 < r)
	{
		for(int i = 0;i<100009;++i)
		{
			pos[i].clear();
		}
		bool correct = false;
		int power = 1;
		long long H = 0;
		int mid = (l+r)/2;

		for(int i = 0;i<L-mid+1;++i)
		{
			if(i == 0)
			{
				for(int j = 0;j<mid;++j)
				{
					H = MOD(H + 1LL*S[mid-1-j]*power);
					if(j < mid-1)
					{
						power = MOD(power*2);
					}
				}
			}
			else
			{
				H = MOD(2*(H - 1LL*S[i-1]*power) + S[i+mid-1]);
			}

			if(!pos[H].empty())
			{
				for(int p : pos[H])
				{
					bool same = true;	
					for(int j = 0;j<mid;++j)
					{
						if(S[p+j] != S[i+j])
						{
							same = false;
							break;
						}
					}
					if(same)
					{
						correct = true;
						break;
					}
				}
			}

			if(correct)
			{
				break;
			}
			else
			{
				pos[H].push_back(i);
			}
		}

		if(correct)
		{
			result = mid;
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	cout<<result;

	return 0;
}


