#include <bits/stdc++.h>

// 6549 Largest Square in Histogram

//높이를 x 로 하는 직사각형의 넓이를 구해서 그 값들 중에 최댓값을 구하면 된다
//i번째 기둥의 높이가 x 라면, i 양 옆의 index들 중에서 x보다 작은 첫 번째 index들을 각각 left, right로 구해서 문제를 풀면 된다
//stack, divide and conquer, segment tree 모두 가능한 문제. 꼭 나중에 혼자 힘으로 다시 풀어볼 것

// update 220412

using namespace std;

static const int INF = 1e9+1;

long long histogram[100001];
int leftindex[100001];
int rightindex[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;

    while(true)
    {
        long long result = 0;
        long long min = INF;
        stack<int> stack;

        cin>>N;
        if(N == 0)
        {
            break;
        }
        
        for(int i = 1;i<=N;++i)
        {
            cin>>histogram[i];
        }

        for(int i = 1;i<=N;++i)
        {
            if(stack.empty())
            {
                stack.push(i);
            }
            else if(histogram[stack.top()] < histogram[i])
            {
                stack.push(i);
            }
            else
            {
                while(!stack.empty() && histogram[stack.top()] > histogram[i])
                {
                    int temp = stack.top();
                    stack.pop();
                    rightindex[temp] = i-1;
                    if(stack.empty())
                    {
                        leftindex[temp] = 1;
                    }
                    else
                    {
                        leftindex[temp] = stack.top() + 1;
                    }
                }
                stack.push(i);
            }
        }
        
        while(!stack.empty())
        {
            int temp = stack.top();
            stack.pop();
            rightindex[temp] = N;
            if(stack.empty())
            {
                leftindex[temp] = 1;
            }
            else
            {
                leftindex[temp] = stack.top() + 1;
            }
        }

        for(int i = 1;i<=N;++i)
        {
            if(result < histogram[i] * (long long)(rightindex[i] - leftindex[i] + 1))
            {
                result = histogram[i] * (long long)(rightindex[i] - leftindex[i] + 1);
            }
        }
        cout<<result<<"\n";
    }
    
	return 0;
}