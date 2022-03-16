#include <bits/stdc++.h>

using namespace std;

// 10830 Matrix multiply 

// update 220317

static long long mod = 1000LL;


vector<vector<long long>> matmult(int N, vector<vector<long long>>& a, vector<vector<long long>>& b)
{
	vector<vector<long long>> mat(N, vector<long long>(N));
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			for(int k = 0;k<N;++k)
			{
				mat[i][j] = (mat[i][j] + (a[i][k] * b[k][j])%mod) % mod;
			}
		}
	}
	return mat;
}

vector<vector<long long>> divcon(int N, long long B, vector<vector<long long>>& a)
{
	if(B==1)
	{
		return a;
	}
	vector<vector<long long>>temp = divcon(N,B/2,a);
	if(B%2==0)
	{
		return matmult(N,temp,temp);
	}
	else
	{
		temp = matmult(N,temp,temp);
		return matmult(N,temp,a);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	long long B;
	cin>>N>>B;
	
	vector<vector<long long>> result;
	vector<vector<long long>> matrix(N,vector<long long>(N));
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			cin>>matrix[i][j];
			matrix[i][j] %= mod;
		}
	}

	result = divcon(N,B,matrix);

	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<"\n";
	}

}