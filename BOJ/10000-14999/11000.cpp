#include <bits/stdc++.h>

// 11000

// update 220425

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

struct Lec
{
	int S,T;
};

int N;
vector<Lec> lec(200001);
int room[200001];
int cnt;
priority_queue<int,vector<int>,greater<int>> pq;

bool compare(const Lec& a, const Lec& b)
{
	return a.S < b.S;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	bool flag = false;

	for(int i = 0;i<N;++i)
	{
		cin>>lec[i].S>>lec[i].T;
		room[i] = -1;
	}

	room[0] = 0;

	sort(lec.begin(),lec.begin()+N,compare);

	for(int i = 0;i<N;++i)
	{
		while(!pq.empty())
		{
			if(pq.top() <= lec[i].S)
			{
				pq.pop();
			}
			else
			{
				break;
			}
		}
		pq.push(lec[i].T);
		cnt = max(cnt,(int)pq.size());
	}
	
	cout<<cnt;

	return 0;
}

