#include <bits/stdc++.h>

// 10000 원 영역

// update 220610

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 300005;
const int MOD = 1e9+7;

struct Circle
{
	long long left, right;
	long long innerR;
	bool adj;
};

int N;
Circle arr[MAX];
stack<Circle> st;
long long result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		long long x, r;
		cin>>x>>r;
		arr[i].left = x - r;
		arr[i].right = x + r;
		arr[i].adj = false;
		arr[i].innerR = 0;
	}

	sort(arr+1,arr+1+N,[](Circle &a, Circle &b)
	{
		if(a.left == b.left)
		{
			return a.right > b.right;
		}
		else
		{
			return a.left < b.left;
		}
	});

	for(int i = 1;i<=N;++i)
	{
		if(st.empty())
		{
			st.push(arr[i]);
		}
		else if(st.top().right >= arr[i].right)
		{
			st.top().innerR += (arr[i].right - arr[i].left);
			st.push(arr[i]);
		}
		else
		{
			while(!st.empty() && st.top().right <= arr[i].left)
			{
				Circle temp = st.top();
				st.pop();
				result++;
				if(temp.innerR == (temp.right-temp.left))
				{
					result++;
				}
			}
			if(!st.empty())
			{
				st.top().innerR += (arr[i].right - arr[i].left);
			}
			st.push(arr[i]);
		}
	}

	while(!st.empty())
	{
		Circle temp = st.top();
		st.pop();
		result++;
		if(temp.innerR == (temp.right-temp.left))
		{
			result++;
		}
	}

	cout<<result+1;

	return 0;
}


