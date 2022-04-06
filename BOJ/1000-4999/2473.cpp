#include <bits/stdc++.h>

// 2473 Triple solution

// update 220328

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long element;
	vector<long long> solution;
	int l,m,r;
	int minl,minm,minr;
	int resultl,resultm,resultr;
	long long resultsolution = numeric_limits<long long>::max();
	long long minsolution;

	cin>>N;

	l = 0;
	r = N-1;

	for(int i = 0;i<N;++i)
	{
		cin>>element;
		solution.push_back(element);
	}
	sort(solution.begin(),solution.end());

	for(int m = 1;m<N-1;++m)
	{
		minsolution = numeric_limits<long long>::max();
		l = 0;
		r = N-1;
		while(l<m && m<r)
		{
			if(abs(minsolution) > abs(solution[l] + solution[m] + solution[r]))
			{
				minsolution = solution[l] + solution[m] + solution[r];
				minl = l;
				minm = m;
				minr = r;
			}
			if(solution[l] + solution[m] + solution[r] > 0)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		if(abs(minsolution) < abs(resultsolution))
		{
			resultsolution = minsolution;
			resultl = minl;
			resultm = minm;
			resultr = minr;
		}
	}
	
	cout<<solution[resultl]<<" "<<solution[resultm]<<" "<<solution[resultr];

	return 0;	
}