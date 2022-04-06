#include <bits/stdc++.h>

// 9527 Counting 1

// update 220405

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long A,B;
    long long result = 0;

    cin>>A>>B;

    for(long long i = A; i <= B; ++i)
    {
        long long temp = i;
        while(temp > 0)
        {
            if(temp % 2 == 1)
            {
                result++;
            }
            temp /= 2;
        }
    }

    cout<<result;

	return 0;
}