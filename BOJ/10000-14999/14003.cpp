#include <bits/stdc++.h>

// 14003 LIS 5

// update 220327

using namespace std;

static const int INF = 1000000001;

int pre[1000001];
int A[1000001];

bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<pair<int,int>> v;
	int num;
	int last = INF;
	stack<int> result;

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>A[i];
		pre[i] = INF;
	}

	for(int i = 1;i<=N;++i)
	{	
		if(v.empty())
		{
			v.push_back({A[i],i});
			last = i;
		}
		else if(v.back().first < A[i])
		{
			pre[i] = v.back().second;
			last = i;
			v.push_back({A[i],i});
		}
		else
		{
			vector<pair<int,int>>::iterator index = lower_bound(v.begin(),v.end(),pair<int,int>(A[i],i),compare);
			(*index).first = A[i];
			(*index).second = i;
			if(index > v.begin())
			{
				pre[i] = (*(index-1)).second;
			}
		}
	}
	cout<<v.size()<<"\n";

	result.push(A[last]);

	while(pre[last] != INF)
	{
		result.push(A[pre[last]]);
		last = pre[last];
	}

	while(!result.empty())
	{
		cout<<result.top()<<" ";
		result.pop();
	}
	

	return 0;	
}