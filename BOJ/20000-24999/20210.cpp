#include <bits/stdc++.h>

// 20210 파일 탐색기

// update 220620

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;

int N;
string arr[MAX];

bool calculating(bool &same, int idx, const string &a, const string &b)
{

	string tempa, tempb;
	int as, ae, bs, be;
	int acnt = 0, bcnt = 0;

	for(int i = idx; (a[i] >= '0' && a[i] <= '9'); ++i)
	{
		if(a[i] != '0')
		{
			as = i;
			break;
		}
		acnt++;
	}
	for(int i = idx; (b[i] >= '0' && b[i] <= '9'); ++i)
	{
		if(b[i] != '0')
		{
			bs = i;
			break;
		}
		bcnt++;
	}

	for(int i = as; (a[i] >= '0' && a[i] <= '9'); ++i)
	{
		ae = i;
	}
	for(int i = bs; (b[i] >= '0' && b[i] <= '9'); ++i)
	{
		be = i;
	}

	tempa = a.substr(as, ae-as+1);
	tempb = b.substr(bs, be-bs+1);

	if(tempa == tempb)
	{
		if(acnt == bcnt)
		{
			same = true;
			return true;
		}
		return acnt < bcnt;
	}
	else if(tempa.length() != tempb.length())
	{
		return tempa.length() < tempb.length();
	}
	else
	{
		return tempa < tempb;
	}
}

bool compare(const string &a, const string &b)
{//true : a 가 더 앞
	int len = min(a.length(), b.length());

	for(int i = 0;i<len;++i)
	{
		if(!(a[i] >= '0' && a[i] <= '9') && !(b[i] >= '0' && b[i] <= '9') && (a[i] == b[i]))
		{
			continue;
		}

		if(a[i] >= '0' && a[i] <= '9' && !(b[i] >= '0' && b[i] <= '9'))
		{
			return true;
		}
		if(b[i] >= '0' && b[i] <= '9' && !(a[i] >= '0' && a[i] <= '9'))
		{
			return false;
		}
		if(a[i] >= '0' && a[i] <= '9' && b[i] >= '0' && b[i] <= '9')
		{
			bool same = false;
			bool ret = calculating(same,i,a,b);
			if(same)
			{
				continue;
			}
			return ret;
		}
		if(a[i] >= 'a' && a[i] <= 'z' && b[i] >= 'a' && b[i] <= 'z')
		{
			return a[i] < b[i];
		}
		if(a[i] >= 'A' && a[i] <= 'Z' && b[i] >= 'A' && b[i] <= 'Z')
		{
			return a[i] < b[i];
		}
		if(a[i] >= 'a' && a[i] <= 'z' && b[i] >= 'A' && b[i] <= 'Z')
		{
			if(a[i] - 'a' == b[i] - 'A')
			{
				return false;
			}
			else
			{
				return a[i]-'a' < b[i]-'A';
			}
		}
		if(a[i] >= 'A' && a[i] <= 'Z' && b[i] >= 'a' && b[i] <= 'z')
		{
			if(a[i] - 'A' == b[i] - 'a')
			{
				return true;
			}
			else
			{
				return a[i]-'A' < b[i]-'a';
			}
		}
	}

	return a.length() < b.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	
	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
	}

	sort(arr+1,arr+1+N,compare);

	for(int i = 1;i<=N;++i)
	{
		cout<<arr[i]<<'\n';
	}

	return 0;
}