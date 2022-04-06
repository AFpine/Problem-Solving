#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;

	for(int t = 0;t<T;++t)
	{
		int N;
		int num;
		int maximum = 1;
		cin>>N;

		priority_queue<int,vector<int>,greater<int>>pq;

		for(int i = 0;i<N;++i)
		{
			cin>>num;
			pq.push(num);
		}

		while(!pq.empty())
		{
			if(pq.top() >= maximum)
			{	
				maximum++;
			}
			pq.pop();
		}

		cout<<"Case #"<<t+1<<": "<<maximum-1<<'\n';
	}

	return 0;
}