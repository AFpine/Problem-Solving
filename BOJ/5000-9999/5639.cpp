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

//BJ 5639 Binary Search Tree

using namespace std;

struct Node
{
    Node* parent {nullptr};
    Node* left {nullptr};
    Node* right {nullptr};
    int value {};
};

void insertNode(Node& N, int num)
{
    if(N.value > num)
    {
        if(N.left == nullptr)
        {
            N.left = new Node{{&N},{},{},num};
            
        }
        else
        {
            insertNode(*(N.left),num);
        }
    }
    else
    {
        if(N.right == nullptr)
        {
            N.right = new Node{{&N},{},{},num};
        }
        else
        {
            insertNode(*(N.right),num);
        }
    }
}

void postorder(const Node& N)
{
    if(N.left != nullptr)
    {
        postorder(*(N.left));
    }
    if(N.right != nullptr)
    {
        postorder(*(N.right));
    }
    cout<<N.value<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    Node root{{},{},{},{}};
    int num;
    int flag=0;
    
    while(cin>>num)
    {
        if(flag==0)
        {
            root.value = num;
            flag = 1;
        }
        else
        {
            insertNode(root,num);
        }
    }

    postorder(root);

    return 0;
    
}
