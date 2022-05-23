#include <bits/stdc++.h>

// 1671 상어의 저녁식사

// update 220523

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 105;

struct Shark
{
    int size,speed,intel;
};

int N;
Shark shark[MAX];
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cntMatch;

bool dfs(int a)
{
    if(visited[a] == true)
    {
        return false;
    }
    visited[a] = true;
    for(auto &b : adj[a])
    {
        if(B[b] == -1 || (visited[B[b]] == false && dfs(B[b]) == true))
        {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    fill(A,A+MAX,-1);
    fill(B,B+MAX,-1);

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>shark[i].size>>shark[i].speed>>shark[i].intel;
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(i == j)
            {
                continue;
            }
            if(shark[i].size >= shark[j].size && shark[i].speed >= shark[j].speed && shark[i].intel >= shark[j].intel)
            {
                if(shark[i].size == shark[j].size && shark[i].speed == shark[j].speed && shark[i].intel == shark[j].intel && i < j) {}
                else
                {
                    adj[i].push_back(j);
                }
            }
        }
    }

    cntMatch = 0;
    for(int i = 1;i<=N;++i)
    {
        fill(visited,visited+MAX,false);
        if(dfs(i) == true)
        {
            cntMatch++;
        }
        fill(visited,visited+MAX,false);
        if(dfs(i) == true)
        {
            cntMatch++;
        }
    }

    cout<<N-cntMatch;
	
	return 0;
}

