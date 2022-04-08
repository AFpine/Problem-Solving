#include <bits/stdc++.h>

// 2623 Music Program (Topology Sort)

// update 220408

using namespace std;

static const int INF = 1e9+1;

struct Singer
{
    int pre = 0;
    vector<int> nxtV;
};

Singer singer[1001];
bool visited[1001];
int singseq[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int pd;
    int result = 0;

    cin>>N>>M;
    queue<int> Q;
    queue<int> resultQ;


    for(int i = 0;i<M;++i)
    {
        cin>>pd;
        for(int j = 0;j<pd;++j)
        {
            cin>>singseq[j];
        }
        for(int j = 0;j<pd-1;++j)
        {
            singer[singseq[j]].nxtV.push_back(singseq[j+1]);
            singer[singseq[j+1]].pre++;
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(singer[i].pre == 0)
        {
            Q.push(i);
            visited[i] = true;
        }
    }

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        resultQ.push(cur);

        for(auto x : singer[cur].nxtV)
        {
            if(visited[x] == false)
            {
                singer[x].pre--;
                if(singer[x].pre == 0)
                {
                    visited[x] = true;
                    Q.push(x);
                }
            }
        }
    }

    if(resultQ.size() != N)
    {
        cout<<"0\n";
    }
    else
    {
        while(!resultQ.empty())
        {
            cout<<resultQ.front()<<'\n';
            resultQ.pop();
        }
    }

   
	return 0;
}