#include <bits/stdc++.h>

// 2263 Tree traverse (Divide and Conquer, Recursion)

// update 220326

using namespace std;

struct Tree
{
	int value;
	Tree* left;
	Tree* right;
};

int inorder[100001];
int postorder[100001];

void treetraverse(int ii, int ij, int pi, int pj, Tree* tree)
{
	if(ii == ij)
	{//this node is leaf
		tree->value = inorder[ii];
		tree->left = nullptr;
		tree->right = nullptr;
		return;
	}
	int k;						
	for(k = 0;k<=ij-ii+1;++k)
	{
		if(inorder[ii+k] == postorder[pj])
		{
			break;
		}
	}
	tree->value = postorder[pj];//or postorder[Aj]

	//in inorder and postorder, [i,k-1] : left subtree , [k+1,j] : right subtree
	if(ij == ii+k)
	{//this node only has left subtree(child)
		tree->left = new Tree();
		treetraverse(ii,ii+k-1,pi,pi+k-1,tree->left);
		tree->right = nullptr;
		return;
	}
	else if(ii == ii+k)
	{//this node only has right subtree(child)
		tree->right = new Tree();
		treetraverse(ii+k+1,ij,pi+k,pj-1,tree->right);
		tree->left = nullptr;
		return;
	}
	else
	{//this node has two subtree(children)
		tree->left = new Tree();
		tree->right = new Tree();
		treetraverse(ii,ii+k-1,pi,pi+k-1,tree->left);
		treetraverse(ii+k+1,ij,pi+k,pj-1,tree->right);
		return;
	}
}

void pretraverse(Tree* root)
{
	cout<<root->value<<" ";
	if(root->left != nullptr)
	{
		pretraverse(root->left);
	}
	if(root->right != nullptr)
	{
		pretraverse(root->right);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 1;
	int n; //[1,n]
	Tree root;

	cin>>n;

	for(int i = 1;i<=n;++i)
	{
		cin>>inorder[i];
	}
	for(int i = 1;i<=n;++i)
	{
		cin>>postorder[i];
	}

	treetraverse(1,n,1,n,&root);
	
	pretraverse(&root);

	return 0;
	
}