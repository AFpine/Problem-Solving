#include <bits/stdc++.h>

using namespace std;

//2252 Line up (Topological Sort)

struct Student
{
    int cnt=0;
    vector<int> Edge;
};

Student student[32001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int a,b;
    queue<int> Q;

    cin>>N>>M;

    for(int i = 1;i<=M;++i)
    {
        cin>>a>>b;
        student[a].Edge.push_back(b);
        student[b].cnt++;
    }

    for(int i = 1;i<=N;++i)
    {
        if(student[i].cnt == 0)
        {
            Q.push(i);
        }
    }

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        cout<<cur<<" ";
        
        for(auto x : student[cur].Edge)
        {
            student[x].cnt--;
            if(student[x].cnt == 0)
            {
                Q.push(x);
            }
        }
    }

	return 0;
}