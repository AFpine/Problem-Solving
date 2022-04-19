#include <bits/stdc++.h>

// 2143 Sum of two arrays (binary search)

// update 220419

using namespace std;

const int INF = 1e9+1;
const int minINF = -1e9-1;

int N,M,T;
long long result = 0;
int A[1001];
vector<int> sumA;
int B[1001];
vector<int> sumB;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;

	cin>>N;
	for(int i = 1;i<=N;++i)
	{
		cin>>A[i];
		A[i] += A[i-1];
	}

	cin>>M;
	for(int i = 1;i<=M;++i)
	{
		cin>>B[i];
		B[i] += B[i-1];
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = 0;j<i;++j)
		{
			sumA.push_back(A[i] - A[j]);
		}
	}
	for(int i = 1;i<=M;++i)
	{
		for(int j = 0;j<i;++j)
		{
			sumB.push_back(B[i] - B[j]);
		}
	}

	
	sort(sumA.begin(),sumA.begin());
	sort(sumB.begin(),sumB.end());


	for(auto x : sumA)
	{
		int high = upper_bound(sumB.begin(),sumB.end(),T-x) - sumB.begin();
		int low = lower_bound(sumB.begin(),sumB.end(),T-x) - sumB.begin();
		result += (high-low);
	}

	cout<<result;


	// for(int i = 1;i<=N;++i)
	// {
	// 	for(int j = 1;j<=i;++j)
	// 	{
	// 		for(int x = 1;x<=M;++x)
	// 		{
	// 			for(int y = 1;y<=x;++y)
	// 			{
	// 				if(sumA[i]-sumA[j] + sumB[x]-sumB[y] == T)
	// 				{
	// 					result++;
	// 				}
	// 			}
	// 		}
	// 	}
	// }


	return 0;
}

