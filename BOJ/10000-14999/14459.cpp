#include <bits/stdc++.h>

// 14459 소가 길을 건너간 이유 11

// update 220620

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int N;
int A[MAX], B[MAX];
vector<pair<int,int>> roadV;
vector<int> LIS;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;

	for(int i = 1;i<=N;++i)
	{//temp종 번호를 가진 소는 i번 목초지에 있다
		int temp;
		cin>>temp;
		A[temp] = i;
	}
	for(int i = 1;i<=N;++i)
	{
		int temp;
		cin>>temp;
		B[temp] = i;
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = -4;j<=4;++j)
		{
			if(i+j >= 1 && i+j <= N)
			{//i 종 번호를 가진 소의 목초지의 위치 (A[i])
			//에서 사이가 좋은 j 종 번호를 가진 목초지로 도로 잇기 (B[j])
				roadV.push_back({A[i], B[i+j]});
			}
		}
	}

	sort(roadV.begin(), roadV.end(), [](pair<int,int> a, pair<int,int> b)
	{//시작점 기준 오름차순, 도착점 기준 내림차순
		if(a.first != b.first)
		{
			return a.first < b.first;
		}
		return a.second > b.second;
	});
	//도착점 기준 내림차순을 하는 이유는
	//문제에서 한 목초지에 두 개 이상의 도로를 설치할 수 없다고 되어있기 때문에
	//같은 출발지를 기준으로 도착지 중 가장 먼 곳을 선택하여 중복되지 않게 하기 위함
	//이렇게 되면, 출발지가 같고 back()보다 더 작은 도착지를 가진 pair를 비교할 때
	//lis의 값이 늘어나지 않고, lower_bound()를 수행하게 된다

	LIS.push_back(-INF);

	for(auto &p : roadV)
	{
		if(LIS.back() < p.second)
		{
			LIS.push_back(p.second);
			result++;
		}
		else
		{
			auto it = lower_bound(LIS.begin(), LIS.end(), p.second);
			*it = p.second;
		}
	}

	cout<<result;

	return 0;
}