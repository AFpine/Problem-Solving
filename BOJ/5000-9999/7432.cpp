#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 555;

struct node {
	string name;
	int depth;
	map<string, int> mp;
	vector<node*> children;
};

int N;

void print(node* cur) {
	for(int i = 0; i < cur->depth-1; ++i) cout<<" ";
	cout<<cur->name<<'\n';

	sort(cur->children.begin(), cur->children.end(), [](node* a, node* b) {
		return a->name < b->name;
	});

	for(auto i : cur->children) {
		print(i);
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	node *root = new node({"root", 0});

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		string S;
		cin>>S;
		int prv = -1;
		auto curnode = root;
		for(int j = 0; j < sz(S); ++j) {
			if(S[j] == '\\') {
				auto s = S.substr(prv+1, j - prv - 1);
				if(curnode->mp[s] == 0) {
					curnode->mp[s] = sz(curnode->children)+1;
					node *tmp = new node({s, curnode->depth+1});
					curnode->children.push_back(tmp);
				}
				curnode = curnode->children[curnode->mp[s]-1];
				prv = j;
			}
		}
		auto s = S.substr(prv+1, sz(S) - prv - 1);
		if(curnode->mp[s] == 0) {
			curnode->mp[s] = sz(curnode->children)+1;
			node *tmp = new node({s, curnode->depth+1});
			curnode->children.push_back(tmp);
		}
		curnode = curnode->children[curnode->mp[s]-1];
	}

	sort(root->children.begin(), root->children.end(), [](node* a, node* b) {
		return a->name < b->name;
	});
	for(auto i : root->children) {
		print(i);
	}

	return 0;
}