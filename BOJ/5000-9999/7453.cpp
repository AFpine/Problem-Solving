#include <bits/stdc++.h>

// 7453 Four integers that sum of 0 (Meet in the middle)

// update 220413

using namespace std;

static const int INF = 1e9+1;

long long A[4001];
long long B[4001];
long long C[4001];
long long D[4001];
vector<long long> X,Y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int left;
	int right;
	int vsize;
	long long result = 0;
	long long sameset = 0;
	long long tempsameX = 0;
	long long tempsameY = 0;
	cin>>N;

	for(int i = 0;i<N;++i)
	{
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			X.push_back(A[i] + B[j]);
			Y.push_back(C[i] + D[j]);
		}
	}

	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	vsize = X.size();
	left = 0;
	right = vsize-1;

	while(left < vsize && right >= 0)
	{
		if(X[left] + Y[right] == 0)
		{
			tempsameX = 1;
			tempsameY = 1;
			while(left+1 < vsize && X[left] == X[left+1])
			{
				tempsameX++;
				left++;
			}
			while(right-1 >= 0 && Y[right] == Y[right-1])
			{
				tempsameY++;
				right--;
			}
			result += tempsameX*tempsameY;
		}
		if(X[left] + Y[right] > 0)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout<<result;

	return 0;
}