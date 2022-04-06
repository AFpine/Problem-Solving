#include <bits/stdc++.h>

// 1644 prime number's contigious sum

// update 220406

using namespace std;

static const int INF = 1e9+1;

int primenumber[4000001];
vector<long long> primevector(1,0);

void primefunc(int N)
{
    for(int i = 2;i<=N;++i)
    {
        primenumber[i] = i;
    }

    for(int i = 2;i<=N;++i)
    {
        if(primenumber[i] == 0)
        {
            continue;
        }
        else
        {
            primevector.push_back(i);
            for(int j = i*2; j<=N ;j += i)
            {
                primenumber[j] = 0;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    int left = 0;
    int right = 0;
    int primelength;
    int result = 0;

    cin>>N;

    primefunc(N);

    primelength = primevector.size();

    for(int i = 1;i<primelength;++i)
    {
        primevector[i] += primevector[i-1];
    }

    while(left <= right && right < primelength)
    {
        if(primevector[right] - primevector[left] == N)
        {
            result++;
        }
        if(primevector[right] - primevector[left] >= N)
        {
            left++;
        }
        else
        {
            right++;
        }
    }

    cout<<result;


	return 0;
}