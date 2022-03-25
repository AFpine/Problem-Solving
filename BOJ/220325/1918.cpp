#include <bits/stdc++.h>

// 1918 Postfix Notation (Data structure, Stack)

// update 220325

using namespace std;

bool isoperator(const char& c)
{
	if(c == '-' || c == '+' || c == '*' || c == '/' || c == '(' || c == ')')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(const char& c)
{
	if(c == '*' || c == '/')
	{
		return 3;
	}
	else if(c == '+' || c == '-')
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<char> output;
	stack<char> oper;
	string s;

	cin>>s;

	for(int i = 0;i<s.length();++i)
	{
		if(isoperator(s[i]) == true)
		{
			if(s[i] == '(')
			{
				oper.push(s[i]);
			}
			else if(s[i] == ')')
			{
				while(true)
				{
					if(oper.top() == '(')
					{
						oper.pop();
						break;
					}
					else
					{
						output.push_back(oper.top());
						oper.pop();
					}
				}
			}
			else
			{
				while(!oper.empty() && precedence(oper.top()) >= precedence(s[i]))
				{
					output.push_back(oper.top());
					oper.pop();
				}
				oper.push(s[i]);
			}
		}
		else
		{
			output.push_back(s[i]);
		}
	}
	while(!oper.empty())
	{
		output.push_back(oper.top());
		oper.pop();
	}

	for(auto x : output)
	{
		cout<<x;
	}

	return 0;
	
}