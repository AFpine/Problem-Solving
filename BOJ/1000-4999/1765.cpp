#include <bits/stdc++.h>

// 1765 닭싸움 팀 정하기

// update 220614

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;

int N,M;
int p[MAX];
vector<int> adj[MAX];
bool selected[MAX];

int find(int a)
{
    if(p[a] < 0)
    {
        return a;
    }
    return p[a] = find(p[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
    {
        return;
    }
    p[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        p[i] = -1;
    }
    cin>>M;

    for(int i = 1;i<=M;++i)
    {
        char op;
        int x,y;
        cin>>op;
        if(op == 'F')
        {
            cin>>x>>y;
            merge(x,y);
        }
        else
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(adj[i].size() >= 2)
        {
            for(int j = 1;j<adj[i].size();++j)
            {
                merge(adj[i][0], adj[i][j]);
            }
        }
    }

    int result = 0;
    for(int i = 1;i<=N;++i)
    {
        if(selected[find(i)] == false)
        {
            selected[find(i)] = true;
            result++;
        }
    }

    cout<<result;

    return 0;
}