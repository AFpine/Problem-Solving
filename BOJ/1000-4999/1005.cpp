#include <bits/stdc++.h>

using namespace std;

//1005 ACF Craft (Topological Sort, Dynamic Programming)

struct Craft
{
    int delay;
    int edgenum;
    vector<int>Edge{};
    priority_queue<int,vector<int>>pq{};
};

Craft craft[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin>>T;

    for(int t = 0;t<T;++t)
    {
        int N,K;
        int X,Y;
        int dest;
        int max = -1;
        queue<int> Q;

        for(int i = 1;i<=1000;++i)
        {
            craft[i].edgenum = 0;
            craft[i].Edge.clear();
            while(!craft[i].pq.empty())
            {
                craft[i].pq.pop();
            }
        }

        cin>>N>>K;

        for(int i = 1;i<=N;++i)
        {
            cin>>craft[i].delay;
        }

        for(int i = 1;i<=K;++i)
        {
            cin>>X>>Y;
            craft[X].Edge.push_back(Y);
            craft[Y].edgenum++;
        }

        for(int i = 1;i<=N;++i)
        {
            if(craft[i].edgenum == 0)
            {
                Q.push(i);
            }
        }

        cin>>dest;

        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            if(!craft[cur].pq.empty())
            {
                craft[cur].delay += craft[cur].pq.top();
            }
            if(cur == dest)
            {
                break;
            }
            for(auto x : craft[cur].Edge)
            {
                craft[x].pq.push(craft[cur].delay);
                if(craft[x].edgenum == craft[x].pq.size())
                {
                    Q.push(x);
                }
            }
        }
        cout<<craft[dest].delay<<'\n';
    }

	return 0;
}