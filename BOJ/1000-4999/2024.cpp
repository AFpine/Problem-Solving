#include <bits/stdc++.h>
 
// 2024 선분 덮기

// update 220719
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+7;

int M;
vector<pii> line;

void input() {
	cin>>M;
	while(true) {
		int l, r;
		cin>>l>>r;
		if(l == 0 && r == 0) break;
		line.push_back({l, r});
	}

	sort(line.begin(), line.end());
}

void solve() {
	bool flag = false;
	int result = 1;
	// pivot : 이 기준보다 왼쪽에서 시작하는 선을 볼 때는 result 값을 추가하지 않는다
	// end : 현재 추가한 간선들의 오른쪽 끝 값
	int pivot = 0, end = -50001;

	// 기준을 만족한 순간, 그 뒤의 line들은 볼 이유가 없으므로 그리디
	for(auto &l : line) {
		if(l.second < 0) continue;

		// 기준보다 왼쪽에서 시작하는 선을 볼 때 : 선분이 끊기지 않고 이어질 때
		if(l.first <= pivot) {
			// 오른쪽으로 제일 큰 위치(연결된)로 갱신
			end = max(end, l.second);
			if(end >= M) {
				//그 위치가 M보다 커지면 가릴 수 있으므로 가능
				flag = true;
				break;
			}
		}
		else {
			// 잡아둔 기준보다 오른쪽에서 시작하는 선을 볼 때 : 결과를 1 증가시킨다 
			// 1개로 가릴 수 있는 최대의 구역을 가렸고, 이제 새로운 구역을 가릴 차례
			result++;
			pivot = end;
			end = max(end, l.second);
			// 앞으로 나올 line들의 시작점은 항상 지금의 시작점보다 크거나 같을 것이다
			// 근데 지금의 시작점이 현재 기준(지금까지 커버된 오른쪽 끝)보다 더 크다면, 그 사이의 공간이 생겨서
			// 가릴 수 없으므로 답은 0이다
			if(l.first > pivot) {
				flag = false;
				break;
			}
			if(end >= M) {
				flag = true;
				break;
			}
		}
	}

	if(flag) cout<<result;
	else cout<<"0";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}