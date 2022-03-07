#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <limits>
#include <cstdint>

// 9663 N-Queen (Backtracking, BruteForce)

using namespace std;

int cnt=0;

int chess[15];

void NQueen(int N, int r)
{
	if(r>=N)
	{
		++cnt;
		return;
	}
	bool flag;
	for(int i = 0;i<N;++i)
	{
		flag = true;
		if(chess[r] != 100)
		{
			return;
		}
		for(int j = 0; j<r; ++j)
		{
			if(chess[j] == i || chess[j] == (i+(r-j)) || chess[j] == (i-(r-j)))
			{
				flag = false;
				break;
			}
		}
		if(!flag)
		{
			continue;
		}
		chess[r] = i;
		NQueen(N,r+1);
		chess[r] = 100;
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin>>N;
	for(int i = 0;i<N;++i)
	{
		chess[i]=100;
	}
	NQueen(N,0);

	cout<<cnt<<"\n";
}
