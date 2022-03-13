#include <bits/stdc++.h>

// 2096 Down (DP, Sliding Window)

// update 220313

using namespace std;

int maxv[2][3];
int minv[2][3];

int maxf(int n1, int n2, int n3)
{
	if(n1 > n2)
	{
		if(n1 > n3)
		{
			return n1;
		}
		else
		{
			return n3;
		}
	}
	else
	{
		if(n2 > n3)
		{
			return n2;
		}
		else
		{
			return n3;
		}
	}
}

int minf(int n1, int n2, int n3)
{
	if(n1 < n2)
	{
		if(n1 < n3)
		{
			return n1;
		}
		else
		{
			return n3;
		}
	}
	else
	{
		if(n2 < n3)
		{
			return n2;
		}
		else
		{
			return n3;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int n1,n2,n3;
	int maxres, minres;

	cin>>N;
	cin>>n1>>n2>>n3;
	maxv[0][0] = n1;
	maxv[0][1] = n2;
	maxv[0][2] = n3;
	minv[0][0] = n1;
	minv[0][1] = n2;
	minv[0][2] = n3;
	for(int i = 1;i<N;++i)
	{
		cin>>n1>>n2>>n3;
		maxv[1][0] = n1 + max(maxv[0][0],maxv[0][1]);
		maxv[1][1] = n2 + maxf(maxv[0][0],maxv[0][1],maxv[0][2]);
		maxv[1][2] = n3 + max(maxv[0][1],maxv[0][2]);
		minv[1][0] = n1 + min(minv[0][0],minv[0][1]);
		minv[1][1] = n2 + minf(minv[0][0],minv[0][1],minv[0][2]);
		minv[1][2] = n3 + min(minv[0][1],minv[0][2]);
		maxv[0][0] = maxv[1][0];
		maxv[0][1] = maxv[1][1];
		maxv[0][2] = maxv[1][2];
		minv[0][0] = minv[1][0];
		minv[0][1] = minv[1][1];
		minv[0][2] = minv[1][2]; 
	}
	maxres = maxf(maxv[0][0],maxv[0][1],maxv[0][2]);
	minres = minf(minv[0][0],minv[0][1],minv[0][2]);
	
	cout<<maxres<<" "<<minres<<"\n";

	return 0;
}