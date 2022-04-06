#include <bits/stdc++.h>

using namespace std;

// 11444 Fibonacci Sequence 6 (Matrix multiplication) 

// update 220317

static long long mod = 1000000007LL;


vector<vector<long long>> matmult(vector<vector<long long>>& a, vector<vector<long long>>& b)
{
	vector<vector<long long>> mat(2, vector<long long>(2));
	for(int i = 0;i<2;++i)
	{
		for(int j = 0;j<2;++j)
		{
			for(int k = 0;k<2;++k)
			{
				mat[i][j] = (mat[i][j] + (a[i][k] * b[k][j])%mod) % mod;
			}
		}
	}
	return mat;
}

vector<vector<long long>> divcon(long long B, vector<vector<long long>>& a)
{
	if(B==1)
	{
		return a;
	}
	vector<vector<long long>>temp = divcon(B/2,a);
	if(B%2==0)
	{
		return matmult(temp,temp);
	}
	else
	{
		temp = matmult(temp,temp);
		return matmult(temp,a);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long N;
	cin>>N;
	
	vector<vector<long long>> result;
	vector<vector<long long>> matrix(2,vector<long long>(2));
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][1] = 0;
	matrix[1][0] = 1;
	
	result = divcon(N,matrix);

	cout<<result[0][1]<<"\n";
}