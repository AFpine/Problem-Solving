#include <bits/stdc++.h>

using namespace std;

char card[21][21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<=20;++i)
	{
		for(int j = 0;j<=20;++j)
		{
			if(i%2==0)
			{
				if(j%2==0)
				{
					card[i][j] = '+';
				}
				else
				{
					card[i][j] = '-';
				}
			}
			else
			{
				if(j%2==0)
				{
					card[i][j] = '|';
				}
				else
				{
					card[i][j] = '.';
				}
			}
		}
	}

	int T;
	cin>>T;

	for(int t = 0;t<T;++t)
	{
		int R,C;
		cin>>R>>C;

		cout<<"Case #"<<t+1<<":\n";

		for(int i = 0;i<=2*R;++i)
		{
			for(int j = 0;j<=2*C;++j)
			{
				if(i <= 1 && j <= 1)
				{
					cout<<'.';
				}
				else
				{
					cout<<card[i][j];
				}
			}
			cout<<"\n";
		}
	}


	return 0;
}