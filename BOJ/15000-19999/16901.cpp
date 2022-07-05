#include <bits/stdc++.h>

// 16901 XOR MST

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
const int MAX = 200005;
const long long MOD = 1e9+7;
const int CMAX = 2;

int N;
int arr[MAX];
ll result = 0;
int bits[31];

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

		if(idx == 31) {
			return;
		}

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
		
		if(child[bits[idx]]) {
			return child[bits[idx]]->find(idx+1, result);
		}
		else {
			return child[!bits[idx]]->find(idx+1, (result|(1<<(30-idx))));
		}
	}
};

void constructBinary(int i) {
	int temp = arr[i];
	for(int j = 30; j >= 0; --j) {
		bits[j] = (temp & 1);
		temp >>= 1;
	}
}

void solve(int s, int e, int bitn) {
	if(s >= e || bitn < 0) return;

	int mid = s;
	while(mid <= e && !(arr[mid] & (1<<bitn))) mid++;
	mid--;

	solve(s, mid, bitn-1);
	solve(mid+1, e, bitn-1);

	if(s > mid || mid >= e) return;

	Trie* root = new Trie();

	for(int i = s; i <= mid; ++i) {
		constructBinary(i);
		root->insert(0);
	}

	int ret = INF;
	for(int i = mid + 1; i <= e; ++i) {
		constructBinary(i);
		ret = min(ret, root->find(0, 0));
	}

	result += (ll)ret;

	delete root;
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie();

	cin>>N;

	for(int i = 1; i <= N; ++i) cin>>arr[i];
	//오름차순 : i(<=30) 번째 bit가 0이었다가 어느 원소를 기준으로 1이 될 것
	sort(arr+1, arr+1+N);

	solve(1, N, 30);

	cout<<result<<'\n';

	return 0;
}