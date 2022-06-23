#include <bits/stdc++.h>

// 1424 새 앨범

// update 220623

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

ll N,L,C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll result = llINF;
	cin>>N>>L>>C;

	for(ll k = (C+1)/(L+1); k >= 1; --k)
	{//cd의 수를 최소화 하려 하기 때문에, 한 cd에 넣는 곡의 수를 최대화 하면서 진행
		if(k > N)
		{
			continue;
		}
		if(k % 13 == 0)
		{
			continue;
		}
		ll r = N % k;
		//floor(N/k) 개의 cd를 사용하고 남은 곡의 갯수는 r개
		if(r > 0)
		{//곡이 남았을 때
			if((r % 13 == 0) && (r + 1 == k))
			{//남은 곡의 수가 13의 배수 개 이고, k개에서 하나 끌어 왔을 때 k-1도 13의 배수가 되면 그냥 새로운 cd 하나가 더 필요하다
				r = 2;
			}
			else
			{
				r = 1;
			}
		}

		result = min(result, N/k + r);
	}

	cout<<result;

	return 0;
}