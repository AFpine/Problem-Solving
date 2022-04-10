#include <bits/stdc++.h>

// 1202 보석 도둑

// update 220410

using namespace std;

struct Jewel
{
    int M;
    int V;
};

vector<Jewel> jewel(300001);
vector<int> bag(300001);

bool JewelMCompare(Jewel& a, Jewel& b)
{
    return a.M < b.M;
}

bool BagCompare(int a, int b)
{
    return a < b;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,K;
    long long sum = 0;
    priority_queue<int,vector<int>> jewelpq;
    int index = 0;

    cin>>N>>K;

    for(int i = 0;i<N;++i)
    {
        cin>>jewel[i].M>>jewel[i].V;
    }
    
    for(int i = 0;i<K;++i)
    {
        cin>>bag[i];
    }

    sort(jewel.begin(),jewel.begin()+N,JewelMCompare);

    sort(bag.begin(),bag.begin()+K,BagCompare);

    for(int k = 0;k<K;++k)
    {
        while(index < N && jewel[index].M <= bag[k])
        {
            jewelpq.push(jewel[index].V);
            index++;
        }
        if(!jewelpq.empty())
        {
            sum += (long long)jewelpq.top();
            jewelpq.pop();
        }
    }

    cout<<sum<<'\n';

    return 0;

}
