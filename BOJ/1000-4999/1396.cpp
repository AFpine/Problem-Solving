#include <bits/stdc++.h>

// 1396 크루스칼의 공

// update 220716

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+7;

int N, M, Q;
int uf[MAX];
pii q[MAX];
vector<pair<int,pii>> edge;
int l[MAX], r[MAX];
pii result[MAX];

vector<int> G[MAX];

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

void input() {
	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		edge.push_back({c, {a, b}});
	}
	//간선 정렬 : kruskal algorithm 을 위함
	sort(edge.begin(), edge.end());

	cin>>Q;
	for(int i = 1; i <= Q; ++i) {
		cin>>q[i].first>>q[i].second;
	}
}

void solve() {
	//l, r : i번 쿼리에서 사용할 간선의 마지막 index를 이분탐색 (0번 간선 ~ M-1번 간선)
	fill(l, l+MAX, 0);
	fill(r, r+MAX, M-1);

	while(true) {
		bool flag = false;
		for(int i = 0; i <= M; ++i) {
			G[i].clear();
		}
		for(int i = 1; i <= Q; ++i) {
			//만약 l[i] <= r[i]가 아니라면, i 번째 쿼리는 이미 처리 되었다 (여기서 시간을 단축)
			if(l[i] <= r[i]) {
				flag = true;
				//(l+r)/2 번째 간선까지 kruskal을 돌리고 i번째 쿼리 처리의 유무를 판단
				G[(l[i]+r[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		fill(uf, uf+MAX, -1);
		for(int i = 0; i < M; ++i) {
			int u = edge[i].second.first;
			int v = edge[i].second.second;
			int c = edge[i].first;

			merge(u, v);
			
			//i번째 간선까지 kruskal을 돌렸을 때, 처리해야 하는 쿼리가 존재하면 (j 번째 쿼리) 한다
			for(auto j : G[i]) {
				int a = q[j].first, b = q[j].second;
				if(find(a) == find(b)) {
					result[j].first = c;
					result[j].second = -uf[find(a)];
					r[j] = i-1;
				}
				else {
					l[j] = i+1;
				}
			}
		}
	}
	for(int i = 1; i <= Q; ++i) {
		if(result[i].first == 0) cout<<"-1\n";
		else cout<<result[i].first<<" "<<result[i].second<<'\n';
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