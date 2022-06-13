#include <bits/stdc++.h>

// 7575 바이러스

// update 220613

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const int MOD = 1e9+7;

int N,K;
string S[MAX];
bool check[MAX];
vector<int> fail;
vector<int> reversefail;

string reverse(const string &W)
{
	string result;

	vector<int> tempV;
	int l = 0, r = 0;
	string tempS;
	while(W[r+1])
	{
		if(W[r] == '_')
		{
			tempS = W.substr(l,r);
			tempV.push_back(stoi(tempS));
			l = r+1;
		}
		r++;
	}
	tempS = W.substr(l,r);
	tempV.push_back(stoi(tempS));

	for(auto i = tempV.rbegin(); i != tempV.rend(); ++i)
	{
		result += to_string(*i);
		result += '_';
	}

	return result;
}

bool KMP(string &W)
{
	string reverseW = reverse(W);
	int reverseM = reverseW.length();
	int M = W.length();

	fill(check,check+MAX,false);
	fail.resize(M+1,0);
	reversefail.resize(reverseM+1,0);

	for(int i = 1,j = 0;i<M;++i)
	{
		while(j > 0 && W[i] != W[j])
		{
			j = fail[j-1];
		}
		if(W[i] == W[j])
		{
			fail[i] = ++j;
		}
	}

	for(int i = 1,j = 0;i<reverseM;++i)
	{
		while(j > 0 && reverseW[i] != reverseW[j])
		{
			j = reversefail[j-1];
		}
		if(reverseW[i] == reverseW[j])
		{
			reversefail[i] = ++j;
		}
	}

	for(int k = 0;k<N;++k)
	{
		int L = S[k].length();

		for(int i = 0, j = 0;i<L;++i)
		{
			while(j > 0 && S[k][i] != W[j])
			{
				j = fail[j-1];
			}
			if(S[k][i] == W[j])
			{
				if(j == M-1)
				{
					check[k] = true;
					j = fail[j];
				}
				else
				{
					++j;
				}
			}
		}
	}

	for(int k = 0;k<N;++k)
	{
		int L = S[k].length();

		for(int i = 0, j = 0;i<L;++i)
		{
			while(j > 0 && S[k][i] != reverseW[j])
			{
				j = reversefail[j-1];
			}
			if(S[k][i] == reverseW[j])
			{
				if(j == reverseM-1)
				{
					check[k] = true;
					j = reversefail[j];
				}
				else
				{
					++j;
				}
			}
		}
	}

	for(int i = 0;i<N;++i)
	{
		if(check[i] == false)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool correct = false;

	int minidx = 0;
	int minval = INF;

	cin>>N>>K;

	for(int i = 0;i<N;++i)
	{
		int n;
		cin>>n;
		if(n < minval)
		{
			minval = n;
			minidx = i;
		}
		for(int j = 0;j<n;++j)
		{
			int temp;
			cin>>temp;
			S[i] += to_string(temp);
			S[i] += '_';
		}
		// cout<<S[i]<<"\n";
	}


	int l = 0, r = 0;
	int cnt = 0;
	string P;
	string reverseP;
	while(S[minidx][r+1])
	{
		if(S[minidx][r+1] == '_')
		{
			cnt++;
		}
		if(cnt == K)
		{
			P = S[minidx].substr(l,(r-l+2));
			// cout<<P<<'\n';
			if(KMP(P) == true)
			{
				correct = true;
				break;
			}
			while(S[minidx][l] != '_')
			{
				l++;
			}
			l++;
			cnt--;
		}
		r++;
	}
	
	if(correct)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}



	return 0;
}


