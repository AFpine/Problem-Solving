#include <bits/stdc++.h>

// 6264 Sub-dictionary

// update 220518

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 105;

int N;
int cnt = 0, cntscc = 0;
int dictidx;
int dfsn[MAX];
int sccidx[MAX];
int indegree[MAX];
int sccIndegree[MAX];
bool studied[MAX];
bool already[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<int> sAdj[MAX];
vector<int> sRAdj[MAX];
map<string,int> dict;
vector<vector<int>> scc;
stack<int> st;
set<string> S;
vector<string> result;

vector<string> split(string input, char delimiter)
{//string split
	vector<string> ret;
	stringstream ss(input);
	string temp;

	while(getline(ss, temp, delimiter))
	{
		ret.push_back(temp);
	}

	return ret;
}

int dfs(int cur)
{
	int res = dfsn[cur] = ++cnt;
	st.push(cur);

	for(auto &next : adj[cur])
	{
		if(dfsn[next] == 0)
		{
			res = min(res,dfs(next));
		}
		else if(finished[next] == false)
		{
			res = min(res,dfsn[next]);
		}
	}

	if(dfsn[cur] == res)
	{
		vector<int> temp;
		while(true)
		{
			int a = st.top();
			st.pop();
			finished[a] = true;
			sccidx[a] = cntscc;
			temp.push_back(a);
			if(cur == a)
			{
				break;
			}
		}
		cntscc++;
		scc.push_back(temp);
	}

	return res;
}

void init()
{
	cnt = 0;
	cntscc = 0;
	dictidx = 0;
	result.clear();
	scc.clear();
	S.clear();
	dict.clear();
	while(!st.empty())
	{
		st.pop();
	}
	for(int i = 0;i<MAX;++i)
	{
		dfsn[i] = 0;
		sccidx[i] = 0;
		finished[i] = false;
		studied[i] = false;
		already[i] = false;
		indegree[i] = 0;
		sccIndegree[i] = 0;
		adj[i].clear();
		sAdj[i].clear();
		sRAdj[i].clear();
	}
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true)
	{	
		init();

		cin>>N;
		if(N == 0)
		{
			break;
		}
		cin.ignore();
		string s;
		vector<string> temps;
		for(int i = 1;i<=N;++i)
		{
			getline(cin,s);
			temps = split(s,' ');
			if(!dict.count(temps[0]))
			{
				S.insert(temps[0]);
				dict[temps[0]] = ++dictidx;
			}
			for(int j = 1;j<temps.size();++j)
			{
				if(!dict.count(temps[j]))
				{
					S.insert(temps[j]);
					dict[temps[j]] = ++dictidx;
				}
				adj[dict[temps[j]]].push_back(dict[temps[0]]);
				indegree[dict[temps[0]]]++;
			}
		}

		for(int i = 1;i<=dictidx;++i)
		{
			if(dfsn[i] == 0)
			{
				dfs(i);
			}
		}

		for(int i = 0;i<cntscc;++i)
		{
			for(auto &sccele : scc[i])
			{
				for(auto &e : adj[sccele])
				{
					if(sccidx[sccele] != sccidx[e])
					{
						sAdj[sccidx[sccele]].push_back(sccidx[e]);
						sRAdj[sccidx[e]].push_back(sccidx[sccele]);
						sccIndegree[sccidx[e]]++;
					}
				}
			}
		}

		queue<int> Q;
		for(int i = 0;i<cntscc;++i)
		{
			if(sccIndegree[i] == 0)
			{
				Q.push(i);
			}
		}

		vector<int> reverseResult;
		while(!Q.empty())
		{
			int cur = Q.front();
			Q.pop();

			reverseResult.push_back(cur);
			if(scc[cur].size() > 1)
			{
				studied[cur] = true;
			}
			for(auto &next : sAdj[cur])
			{
				if(--sccIndegree[next] == 0)
				{
					Q.push(next);
				}
			}
		}

		for(int i = cntscc-1;i>=0;--i)
		{
			int cur = reverseResult[i];
			if(studied[cur] == true)
			{
				for(auto &e : scc[cur])
				{
					already[e] = true;
				}
				for(auto &prev : sRAdj[cur])
				{
					studied[prev] = true;
				}
			}
		}

		for(auto &s : S)
		{
			if(already[dict[s]] == true)
			{
				result.push_back(s);
			}
		}

		sort(result.begin(),result.end());

		cout<<result.size()<<'\n';
		for(auto &s : result)
		{
			cout<<s<<" ";
		}

	}


	
	return 0;
}