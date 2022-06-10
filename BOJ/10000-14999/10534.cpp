#include <bits/stdc++.h>

// 10534 락페스티벌

// update 220610

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 50005;
const int MOD = 1e9+7;

struct Line
{
	long long pos, S, E;
	int idx;
	bool start;
};

vector<Line> rL, cL;
int N;
long long p[MAX];
long long square[MAX];

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
	p[b] += p[a];
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
		long long x,y,w,h;
		cin>>x>>y>>w>>h;

		rL.push_back({x,y,y+h,i,true});
		rL.push_back({x+w,y,y+h,i,false});
		cL.push_back({y,x,x+w,i,true});
		cL.push_back({y+h,x,x+w,i,false});

		p[i] = -w*h;
	}

	sort(rL.begin(),rL.end(),[](Line &a, Line &b)
	{
		if(a.pos == b.pos)
		{
			return a.S < b.S;
		}
		return a.pos < b.pos;
	});
	sort(cL.begin(),cL.end(),[](Line &a, Line &b)
	{
		if(a.pos == b.pos)
		{
			return a.S < b.S;
		}
		return a.pos < b.pos;
	});

	
	for(int i = 0;i<2*N-1;++i)
	{
		if(rL[i].pos == rL[i+1].pos)
		{
			if(rL[i].E >= rL[i+1].S)
			{
				long long mini = min(rL[i].S, rL[i+1].S);
				long long maxi = max(rL[i].E, rL[i+1].E);
				rL[i].S = rL[i+1].S = mini;
				rL[i].E = rL[i+1].E = maxi;
				if(find(rL[i].idx) != find(rL[i+1].idx))
				{
					merge(rL[i].idx, rL[i+1].idx);
				}
			}
		}
	}

	for(int i = 0;i<2*N-1;++i)
	{
		if(cL[i].pos == cL[i+1].pos)
		{
			if(cL[i].E >= cL[i+1].S)
			{
				long long mini = min(cL[i].S, cL[i+1].S);
				long long maxi = max(cL[i].E, cL[i+1].E);
				cL[i].S = cL[i+1].S = mini;
				cL[i].E = cL[i+1].E = maxi;
				if(find(cL[i].idx) != find(cL[i+1].idx))
				{
					merge(cL[i].idx, cL[i+1].idx);
				}
			}
		}
	}
	
	long long result = 0;
	for(int i = 1;i<=N;++i)
	{
		result = max(result,-p[i]);
	}
	
	cout<<result;

	return 0;
}


