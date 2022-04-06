#include <bits/stdc++.h>

using namespace std;

int factor[1000001];

struct compare
{
    bool operator()(int a, int b)
    {
        return factor[a] > factor[b];
    }
};

struct Module
{
	int factor;
	int point;
    int multi;
    priority_queue<int,vector<int>,compare> modpq;
};

Module chain[100001];
bool visited[100001];

long long maximum = 0;

void DFS(int i, int fun, queue<int>& Q)
{
    int nxt = chain[i].point;
    if(fun > factor[i])
    {
        factor[i] = fun;
    }
    if(chain[i].multi >= 2)
    {
        factor[i] = max(factor[i], factor[chain[i].modpq.top()]);
        chain[i].modpq.pop();
        while(!chain[i].modpq.empty())
        {
            maximum += factor[chain[i].modpq.top()];
            chain[i].modpq.pop();
        }
        visited[i] = true;
    }
    if(nxt == 0)
    {
        maximum += factor[i];
        return;
    }
    if(visited[nxt] == false && chain[nxt].multi == 1)
    {
        visited[nxt] = true;
        DFS(nxt,factor[i],Q);
    }
    else if(visited[nxt] == false && chain[nxt].multi >= 2)
    {
        chain[nxt].modpq.push(i);
        if(chain[nxt].multi == chain[nxt].modpq.size())
        {
            Q.push(nxt);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;

	for(int t = 0;t<T;++t)
	{
		int N;
		maximum = 0;
        queue<int> initQ;

		cin>>N;

		for(int i = 1;i<=N;++i)
		{
			visited[i] = false;
		}
		for(int i = 1;i<=N;++i)
		{
			cin>>factor[i];
            chain[i].multi = 0;
		}
		for(int i = 1;i<=N;++i)
		{
			cin>>chain[i].point;
			chain[chain[i].point].multi++;
		}
		for(int i = 1;i<=N;++i)
		{
			if(chain[i].multi == 0)
			{
                initQ.push(i);
			}
		}

		while(!initQ.empty())
		{
			int cur = initQ.front();
            initQ.pop();
            DFS(cur,factor[cur],initQ);
		}

		cout<<"Case #"<<t+1<<": "<<maximum<<'\n';
	}

	return 0;
}