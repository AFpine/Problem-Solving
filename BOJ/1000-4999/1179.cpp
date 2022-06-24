#include <bits/stdc++.h>

// 1179 마지막 요세푸스 문제

// update 220623

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

ll N,K;

ll recur(ll n, ll k)
{//index is [0,n-1]
	if(n == 1)
	{//f(1,k) = 0;
		return 0;
	}
	if(k == 1)
	{//if k is 1, result is n-1
		return n-1;
	}
	if(n < k)
	{//1 < n < k 일 때의 일반항
		return (recur(n-1,k)+k) % n;
	}

	ll res = recur(n-(n/k),k);
	if(res < (n % k))
	{
		return res - (n % k) + n;
	}
	else
	{
		return ((res - (n % k))*k) / (k-1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N>>K;

	cout<<recur(N,K)+1;

	return 0;
}