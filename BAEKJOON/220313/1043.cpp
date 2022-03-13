#include <bits/stdc++.h>

// 1043 Lie (Union-find)

// update 220313

using namespace std;


int parent[51];
bool knowtrue[51];

int find(int n)
{
	while(parent[n] != n)
	{
		n = parent[n];
	}
	return n;
}

void mergeset(int n1, int n2)
{
	int parent1 = find(n1);
	int parent2 = find(n2);

	if(knowtrue[parent1] == true)
	{
		parent[parent2] = parent1;
	}
	else if(knowtrue[parent2] == true)
	{
		parent[parent1] = parent2;
	}
	else
	{
		parent[parent2] = parent1;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; 	//N is num of people, M is num of party
	int temp;
	vector<vector<int>>partys;
	int cnt=0;

	for(int i = 0;i<51;++i)
	{
		parent[i] = i;
	}

	cin>>N>>M;
	cin>>temp;
	for(int i = 0;i<temp;++i)
	{
		int n;
		cin>>n;
		knowtrue[n] = true;
	}
	
	for(int i = 0;i<M;++i)
	{
		int n;
		vector<int>party;
		cin>>temp;
		if(temp)
		{
			for(int j = 0;j<temp;++j)
			{
				cin>>n;
				party.push_back(n);
			}
			for(int j=1;j<party.size();++j)
			{
				mergeset(party[0],party[j]);
			}
			partys.push_back(party);
		}
	}
	
	for(auto party : partys)
	{
		if(knowtrue[find(party[0])] == false)
		{
			++cnt;
		}
	}
	cout<<cnt<<"\n";
}