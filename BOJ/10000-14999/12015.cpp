#include <bits/stdc++.h>

// 12015 LIS 2 (binary search or segment tree O(nlogn))

// update 220327

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> v;
	int num;

	cin>>N;

	for(int i = 0;i<N;++i)
	{	
		cin>>num;
		if(v.empty())
		{
			v.push_back(num);
		}
		if(v.back() < num)
		{
			v.push_back(num);
		}
		else
		{
			vector<int>::iterator index = lower_bound(v.begin(),v.end(),num);
			(*index) = num;
		}
	}
	cout<<v.size()<<"\n";
	

	return 0;	
}