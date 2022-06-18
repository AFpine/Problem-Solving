#include <bits/stdc++.h>

// 20055 컨베이어 벨트 위의 로봇

// update 220618

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 205;

long long result;
int broken;
int N,K;
int A[MAX];
bool robot[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i = 1;i<=2*N;++i)
	{
		cin>>A[i];
	}

	int S = 1;
	deque<int> dq;
	for(int i = 1;i<=N;++i)
	{
		dq.push_back(i);
	}

	while(true)
	{
		result++;
		S--;
		if(S == 0)
		{
			S = 2*N;
		}
		
		dq.pop_back();
		dq.push_front(S);
		robot[dq.back()] = false;
		
		for(auto it = dq.rbegin()+1; it != dq.rend(); ++it)
		{
			if(robot[*(it)] == true && robot[*(it-1)] == false && A[*(it-1)] > 0)
			{
				robot[*(it)] = false;
				robot[*(it-1)] = true;
				A[*(it-1)]--;

				if(A[*(it-1)] == 0)
				{
					broken++;
				}
				
				if((*(it-1))  == dq.back())
				{
					robot[dq.back()] = false;
				}

			}
		}

		if(A[S] > 0)
		{
			A[S]--;
			robot[S] = true;
			if(A[S] == 0)
			{
				broken++;
			}
		}

		if(broken >= K)
		{
			break;
		}
	}

	cout<<result;

	return 0;
}