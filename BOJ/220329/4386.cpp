#include <bits/stdc++.h>

// 4386 Making Constellation (MST, Prim algorithm) 

// update 220328

using namespace std;

pair<double,double> star[101];
bool visited[101];

int nowindex = 0;

double distance(const pair<double,double>& a, const pair<double,double>& b)
{
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

struct compare
{
	bool operator()(const pair<int,int>& a, const pair<int,int>& b)
	{
		return distance(star[a.first],star[a.second]) > distance(star[b.first],star[b.second]);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	double a,b;
	double result = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

	cin>>n;

	for(int i = 1;i<=n;++i)
	{
		cin>>a>>b;
		star[i] = {a,b};
	}

	visited[1] = true;
	nowindex = 1;
	for(int i = 1;i<=n;++i)
	{
		pq.push({nowindex,i});
	}
	for(int i = 1;i<=n-1;++i)
	{
		while(!pq.empty())
		{
			pair<int,int> cur = pq.top();
			pq.pop();
			if(visited[cur.second] == false)
			{
				visited[cur.second] = true;
				result += distance(star[cur.first],star[cur.second]);
				nowindex = cur.second;
				break;
			}
		}
		for(int j = 1;j<=n;++j)
		{
			pq.push({nowindex,j});
		}
	}

	cout<<result<<"\n";

	return 0;	
}