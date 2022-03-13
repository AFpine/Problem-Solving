#include <bits/stdc++.h>

// 15686 Chicken Delivery (BruteForce)

// update 220312

using namespace std;

int city[50][50];
bool check[50][50];
int res = numeric_limits<int>::max();

int citydist(vector<pair<int,int>>& house, vector<pair<int,int>>& chicken)
{
	int sum=0;
	int mindist = numeric_limits<int>::max();
	for(auto h : house)
	{
		mindist = numeric_limits<int>::max();
		for(auto c : chicken)
		{
			mindist = min(mindist, abs(h.first-c.first) + abs(h.second-c.second));
		}
		sum += mindist;
	}
	return sum;
}

void setchicken(vector<pair<int,int>>& chicken, vector<pair<int,int>>& h, vector<pair<int,int>>& v, int idx, int num, int M)
{
	if(num == M)
	{
		res = min(res,citydist(h,chicken));
	}
	else
	{
		for(int i = idx; i<v.size(); ++i)
		{
			if(check[v[i].first][v[i].second] == false)
			{
				check[v[i].first][v[i].second] = true;
				chicken.push_back({v[i].first, v[i].second});
				setchicken(chicken,h,v,i,num+1,M);
				check[v[i].first][v[i].second] = false;
				chicken.erase(chicken.end()-1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;
	vector<pair<int,int>> house;
	vector<pair<int,int>> allchicken;
	vector<pair<int,int>> selectchicken;
	cin>>N>>M;

	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			cin>>city[i][j];
			if(city[i][j] == 1)
			{
				house.push_back({i,j});
			}
			else if(city[i][j] == 2)
			{
				allchicken.push_back({i,j});
			}
		}
	}

	setchicken(selectchicken, house, allchicken,0,0,M);

	cout<<res<<"\n";

}
