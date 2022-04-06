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

// 1753 Shortest Path (Dijkstra)  using Priority_queue for min Heap

using namespace std;

static int INF = 100000000;

struct Vertex
{
    int number{};
    vector<pair<int,int>> E{};
    int dist {INF};
    bool visited {false};
};

struct compare
{
    bool operator()(const Vertex &a, const Vertex &b) const
    {
        return a.dist>b.dist;
    }
};

vector<Vertex> vv(20001, Vertex{});
int distarr[20001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int V,E;
    int K;      //start vertex
    int n1,n2,n3;
    int cnt=0;
    priority_queue<Vertex, vector<Vertex>,compare> pq;

    cin>>V>>E>>K;

    for(int i = 1;i<=V;++i)
    {
        vv[i].number = i;
    }

    for(int i = 1;i<=V;++i)
    {
        distarr[i] = INF;
    }

    for(int i = 0;i<E;++i)
    {
        cin>>n1>>n2>>n3;
        vv[n1].E.push_back(pair<int,int>(n2,n3));
        // first is dest vertex, second is path value
    }

    vv[K].dist = 0;
    
    for(int i = 1;i<=V;++i)
    {
        pq.push(vv[i]);
    }

    while(!pq.empty())
    {
        Vertex temp = pq.top();
        pq.pop();
        if(temp.visited == true)
        {
            continue;
        }
        temp.visited = true;
        for(auto x : temp.E)
        {
            if(vv[x.first].visited == false && temp.dist + x.second < vv[x.first].dist)
            {
                vv[x.first].dist = temp.dist + x.second;
                pq.push(vv[x.first]);
            }
        }
    }

    for(int i=1;i<=V;++i)
    {
        if(vv[i].dist == numeric_limits<int>::max() || vv[i].dist == INF)
        {
            cout<<"INF"<<"\n";
            continue;
        }
        cout<<vv[i].dist<<"\n";
    }
    
}
