#include <bits/stdc++.h>

// 13538 XOR 쿼리

// update 220719

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = (1<<19) - 1;
const long long MOD = 1e9+7;

struct Node {
	int val {0};
	Node *l {nullptr}, *r {nullptr};
};

int M;

void seginit(int s, int e, Node* tree) {
	if(s == e) {
		tree->val = 0;
		return;
	}
	int mid = (s+e)/2;
	tree->l = new Node();
	tree->r = new Node();
	seginit(s, mid, tree->l);
	seginit(mid+1, e, tree->r);
	tree->val = tree->l->val + tree->r->val;
}

void update(int s, int e, Node* prv, Node* tree, int pos, int x) {
	if(s > pos || e < pos) return;
	if(s == e) {
		tree->val = prv->val + x;
		return;
	}
	int mid = (s+e)/2;
	if(pos <= mid) {
		tree->l = new Node();
		tree->r = prv->r;
		update(s, mid, prv->l, tree->l, pos, x);
	}
	else {
		tree->r = new Node();
		tree->l = prv->l;
		update(mid+1, e, prv->r, tree->r, pos, x);
	}
	tree->val = tree->l->val + tree->r->val;
}

int query(int s, int e, Node* tree, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree->val;
	int mid = (s+e)/2;
	return query(s, mid, tree->l, l, r) + query(mid+1, e, tree->r, l, r);
}

// [i,j] tree에서 k번째로 작은 수
// l : tree[i-1], r : tree[j]
int kthquery(Node* l, Node* r, int s, int e, int k) {
	if(s == e) return s;
	int mid = (s+e)/2;
	// PST 구간 안에서의 쿼리를 실행해야 하기 때문에, 쿼리의 모든 연산은 누적합 같은 테크닉을 사용
	int diff = r->l->val - l->l->val;
	if(k <= diff) return kthquery(l->l, r->l, s, mid, k);
	else return kthquery(l->r, r->r, mid+1, e, k - diff);
}

int xorquery(Node* l, Node* r, int s, int e, int x) {
	if(s == e) return s;
	int mid = (s+e)/2;
	int left = r->l->val - l->l->val;
	int right = r->r->val - l->r->val;

	// left, right 둘 중에 하나라도 비어있으면 비어있지 않은 곳으로 가야한다
	// mid : 현재 고려해야 하는 비트는 mid를 기준으로 왼쪽에 0, 오른쪽에 1로 나누어져 있다
	// [(e-s+1)/2 & x] : 현재 고려해야 하는 위치에 1을 가지고 있는 2진수 값 (k 번째 비트만 1인 수)

	if((left > 0) && (((e - s + 1) / 2) & x) || right == 0) return xorquery(l->l, r->l, s, mid, x);
	else return xorquery(l->r, r->r, mid+1, e, x);
}

void input() {
	cin>>M;
}

void solve() {
	// size 를 500000보다 큰 2의 제곱수로 해줘야 함 [0, 1<<19 - 1] (xor 쿼리 때문에)
	vector<Node*> tree(MAX);
	tree[0] = new Node();
	seginit(0, MAX, tree[0]);
	int t = 0;

	while(M--) {
		int op, l, r, x, k;
		cin>>op;

		if(op == 1) {
			cin>>x;
			tree[++t] = new Node();
			update(0, MAX, tree[t-1], tree[t], x, 1);
		}
		else if(op == 2) {	//xor query : 구간은 [0, MAX]이므로 정확히 비트에 대해 연산할 수 있다
			cin>>l>>r>>x;
			cout<<xorquery(tree[l-1], tree[r], 0, MAX, x)<<'\n';
		}
		else if(op == 3) {
			cin>>k;
			t -= k;
		}
		else if(op == 4) {	//구간 합
			cin>>l>>r>>x;
			cout<<query(0, MAX, tree[r], 1, x) - query(0, MAX, tree[l-1], 1, x)<<'\n';
		}
		else {	//k번 째 원소 찾기 : 머지소트트리 같이 세그트리 안의 원소들이 정렬되어 있을 때 가능
				//이 문제에서는 트리의 인덱스 자체를 배열 A의 원소로 보고 있기 때문에 당연히 정렬되어있음
			cin>>l>>r>>k;
			cout<<kthquery(tree[l-1], tree[r], 0, MAX, k)<<'\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}