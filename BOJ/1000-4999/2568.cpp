#include <bits/stdc++.h>

// 2568 전깃줄 - 2

// update 220620

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 500005;

int N;
int connected[MAX];
int prevv[MAX];
bool selected[MAX];
vector<pair<int,int>> lineV;
vector<int> lis;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(selected,selected+MAX,false);
	fill(prevv,prevv+MAX,-1);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{	
		int a,b;
		cin>>a>>b;
		connected[b] = a;
		lineV.push_back({a,b});
	}

	sort(lineV.begin(), lineV.end(), [](pair<int,int> a, pair<int,int> b)
	{
		if(a.first != b.first)
		{
			return a.first < b.first;
		}
		return a.second > b.second;
	});

	lis.push_back(-1);

	for(auto &p : lineV)
	{//한 원소가 lis를 이룰 때의 자신의 직전 원소를 prevv 배열에 저장
		if(lis.back() < p.second)
		{
			prevv[p.second] = lis.back();
			lis.push_back(p.second);
		}
		else
		{
			auto it = lower_bound(lis.begin(), lis.end(), p.second);
			prevv[p.second] = *(prev(it));
			*it = p.second;
		}
	}

	int temp = lis.back();
	while(temp != -1)
	{//lis.back()에 있는 원소가 실제 구한 lis의 마지막 원소
    //그 원소를 따라서 lis를 구성하는 원소들을 체크한다
		selected[connected[temp]] = true;
		temp = prevv[temp];
	}

	for(auto &p : lineV)
	{//체크되지 못한 원소들은 삭제해야 한다
		if(selected[p.first] == false)
		{
			result.push_back(p.first);
		}
	}

	sort(result.begin(),result.end());
	cout<<result.size()<<'\n';
	for(auto &i : result)
	{
		cout<<i<<'\n';
	}

	return 0;
}