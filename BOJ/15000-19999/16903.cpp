#include <bits/stdc++.h>

// 16903 수열과 쿼리 20

// update 220705

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 5005;
const long long MOD = 1e9+7;
const int CMAX = 2;

int M;
int op, x;
int bits[31] = {0};

struct Trie {
	int cnt = 0;
	Trie* child[2];

	Trie() {
		cnt = 0;
		child[0] = child[1] = nullptr;
	}
	~Trie() {
		delete child[0];
		delete child[1];
	}

	void insert(int idx) {
		cnt++;

		if(idx == 31) return;

		if(!child[bits[idx]]) child[bits[idx]] = new Trie();

		child[bits[idx]]->insert(idx+1);
	}

	void erase(int idx) {
		cnt--;

		if(idx == 31) return;

		child[bits[idx]]->erase(idx+1);

		if(child[bits[idx]]->cnt == 0) {
			delete child[bits[idx]];
			child[bits[idx]] = nullptr;
		}
	}

	int find(int idx, int result) {
		if(idx == 31) return result;
		
		if(child[!bits[idx]]) {
			return child[!bits[idx]]->find(idx+1, (result|(1<<(30-idx))));
		}
		else {
			return child[bits[idx]]->find(idx+1, result);
		}
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie();
	root->insert(0);
	cin>>M;
	while(M--) {
		cin>>op>>x;

		for(int i = 30; i >= 0; --i) {
			bits[i] = (x & 1);
			x >>= 1;
		}
		// for(int i = 0; i < 32; ++i) cout<<bits[i];
		// cout<<'\n';

		if(op == 1) root->insert(0);
		else if(op == 2) root->erase(0);
		else cout<<root->find(0,0)<<'\n';
	}

	return 0;
}