#include <bits/stdc++.h>

// 19940 피자 오븐

// update 220622

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 3005;
const long long MOD = 1e9+7;

int f1,f2,f3,f4,f5;
int T;
int N;

void init()
{
	f1 = 0,f2 = 0,f3 = 0,f4 = 0,f5 = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		init();
		cin>>N;

		if(N > 60)
		{
			f1 += N/60;
			N %= 60;
		}
		if(N > 35)
		{
			f1++;
			N = 60 - N;
			f3 += N/10;
			N %= 10;
			if(N > 5)
			{
				f3++;
				f4 += 10-N;
			}
			else
			{
				f5 += N;
			}
		}
		else
		{
			f2 += N/10;
			N %= 10;
			if(N > 5)
			{
				f2++;
				f5 += 10-N;
			}
			else
			{
				f4 += N;
			}
		}

		cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<" "<<f5<<'\n';
	}
	


	return 0;
}