#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <limits>
#include <cstdint>

//

using namespace std;

int graph[101][101];

int INF = 100000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N;
    cin>>N;
    int num;

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            cin>>num;
            if(num == 1)
            {
                graph[i][j] = num;
            }
            else
            {
                graph[i][j] = INF;
            }
        }
    }
    
    for(int k = 1;k<=N;++k)
    {
        for(int i = 1;i<=N;++i)
        {
            for(int j = 1;j<=N;++j)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(graph[i][j] < INF)
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
            cout<<" ";
        }
        cout<<"\n";
    }
    
}
