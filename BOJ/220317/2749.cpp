#include <bits/stdc++.h>

using namespace std;

// 2749 Fibonacci sequence 3 (Pisano Period) 
//Should study about Pisano Period proof

// update 220317

static int mod = 1000000;
static int P = 1500000;
long long fibo[1500000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    long long n;
    cin>>n;

    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i = 2;i<P;++i)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2])%mod;
    }
    cout<<fibo[n%P]<<'\n';

}