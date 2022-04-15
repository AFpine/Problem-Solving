#include <bits/stdc++.h>

// 9007 Canoe man

// update 220414

using namespace std;

static const int INF = 1e9+1;

int canoe[4][1001];
int k,n;
int result;
int diff;
int leftidx,rightidx;
int vectorsize;

void Canoe()
{
	result = INF;
	diff = INF;
	vector<int> X,Y;
	cin>>k>>n;

	for(int i = 0;i<4;++i)
	{
		for(int j = 0;j<n;++j)
		{
			cin>>canoe[i][j];
		}
	}

	for(int i = 0;i<n;++i)
	{
		for(int j = 0;j<n;++j)
		{
			X.push_back(canoe[0][i] + canoe[1][j]);
			Y.push_back(canoe[2][i] + canoe[3][j]);
		}
	}

	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	vectorsize = Y.size();
	leftidx = 0;
	rightidx = vectorsize-1;

	while(leftidx < vectorsize && rightidx >= 0)
	{
		if(abs(k - (X[leftidx] + Y[rightidx])) < diff)
		{
			result = X[leftidx] + Y[rightidx];
			diff = abs(k - (X[leftidx] + Y[rightidx]));
		}
		else if(abs(k - (X[leftidx] + Y[rightidx])) == diff && result > X[leftidx]+Y[rightidx])
		{
			result = X[leftidx] + Y[rightidx];
		}

		if(X[leftidx] + Y[rightidx] > k)
		{
			rightidx--;
		}
		else
		{
			leftidx++;
		}
	}

	cout<<result<<'\n';

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;

	for(int t = 0;t<T;++t)
	{
		Canoe();
	}

	return 0;
}