#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

struct Edge
{
    int a,b,w;
    bool operator<(const Edge &e)
    {
        return w > e.w;
    }
};
int N,M;
int position[MAX];
int p[MAX];
vector<Edge> edge;
bool correct;
bool good = true;

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
    p[b] = a;
}

void init()
{
    for(int i = 1;i<MAX;++i)
    {
        p[i] = -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        cin>>position[i];
        if(i != position[i])
        {
            good = false;
        }
    }

    for(int i = 1;i<=M;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edge.push_back({a,b,w});
    }
    
    if(good)
    {
        cout<<"-1";
        return 0;
    }

    sort(edge.begin(),edge.end());

    int l = 0;
    int r = M-1;        
    int result;
    while(l < r)
    {
        init();
        correct = true;
        int mid = (l+r)/2;
        for(int i = 0;i<=mid;++i)
        {
            merge(edge[i].a, edge[i].b);
        }
        for(int i = 1;i<=N;++i)
        {
            if(find(i) != find(position[i]))
            {
                correct = false;
            }
        }
        if(correct)
        {
            result = edge[mid].w;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout<<result;


    return 0;
}