#include <bits/stdc++.h>

// 11049 Matrix Chain Multiplication (Dynamic Programming)

// update 220328

using namespace std;

pair<int,int> matrix[501];
int m[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int a,b;
	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>a>>b;
		m[i][i] = 0;
		matrix[i] = {a,b};
	}

	for(int l = 2; l<=N;++l)
	{//length of matrix (multiplication result of one matrix is 0)
		for(int i = 1; i <= N-l+1;++i)
		{
			int j = i+l-1;
			//j is last matrix when multiplication start at i st matrix
			m[i][j] = numeric_limits<int>::max();
			for(int k = i;k<=j;++k)
			{
				m[i][j] = min(m[i][j],(m[i][k]+m[k+1][j]+matrix[i].first*matrix[k].second*matrix[j].second));
			}
		}
	}
	cout<<m[1][N]<<"\n";
	
	return 0;	
}