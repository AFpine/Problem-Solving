#include <bits/stdc++.h>

// 2166 Area of Polygon

// update 220326

using namespace std;

double x[10001];
double y[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double result=0;
	double firstsum = 0, secondsum = 0;
	int N;

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>x[i]>>y[i];
	}

	for(int i = 1;i<=N-1;++i)
	{
		firstsum += x[i]*y[i+1];
		secondsum += y[i]*x[i+1];
	}

	firstsum += x[N]*y[1];
	secondsum += y[N]*x[1];
	
	result = abs(firstsum - secondsum)/2;

	result = round(result*10)/10;

	printf("%.1f",result);

	return 0;	
}