#include <bits/stdc++.h>

// 12865 Standard Backpack (Knapsack Problem)

//update 220310

using namespace std;

int arr[101][100001];
int w[101];
int v[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,K;
	int W,V;
	int maxvalue;
	cin>>N>>K;
	
	for(int i = 1;i<=N;++i)
	{
		cin>>W>>V;
		w[i] = W;
		v[i] = V;
	}

	for(int i = 1; i<=N; ++i)
	{
		for(int j = 1; j<=K; ++j)
		{
			if(j-w[i] >= 0)
			{	//j용량 배낭에 i번째 물건을 넣을 수 있다면?
				//(i번째 물건의 용량이, i-1까지 넣었던 배낭에 남는 공간보다 작거나 같다면)
				arr[i][j] = max(arr[i-1][j], arr[i-1][j-w[i]] + v[i]);
			}
			else
			{	//그렇지 않다면 i번째 물건은 넣지 못한다
				arr[i][j] = arr[i-1][j];
			}
		}
	}
	
	cout<<arr[N][K]<<"\n";

	
	
}
