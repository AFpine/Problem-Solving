#include <bits/stdc++.h>

using namespace std;

int C[3];
int M[3];
int Y[3];
int K[3];
int minimum[4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;

	for(int t = 0;t<T;++t)
	{
		int sum = 0;
		int remain = 1000000;

		for(int i = 0;i<4;++i)
		{
			minimum[i] = 1000001;
		}

		for(int i = 0;i<3;++i)
		{
			cin>>C[i]>>M[i]>>Y[i]>>K[i];
		}

		for(int i = 0;i<3;++i)
		{
			if(minimum[0] > C[i])
			{
				minimum[0] = C[i];
			}
			if(minimum[1] > M[i])
			{
				minimum[1] = M[i];
			}
			if(minimum[2] > Y[i])
			{
				minimum[2] = Y[i];
			}
			if(minimum[3] > K[i])
			{
				minimum[3] = K[i];
			}
		}

		for(int i = 0;i<4;++i)
		{
			sum += minimum[i];
		}

		cout<<"Case #"<<t+1<<": ";

		if(sum < 1000000)
		{
			cout<<"IMPOSSIBLE\n";
		}
		else
		{
			for(int i = 0;i<4;++i)
			{
				if(remain < minimum[i])
				{
					minimum[i] = remain;
					cout<<minimum[i]<<" ";
				}
				else
				{
					cout<<minimum[i]<<" ";
				}
				remain -= minimum[i];
			}
			cout<<"\n";	
		}
	}

	return 0;
}