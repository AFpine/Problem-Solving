#include <bits/stdc++.h>

// 9249 최장 공통 부분 문자열

// update 220702

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 200010;
const long long MOD = 1e9+7;

string S, T;
//sa[i] : i번째 순위를 가지는 suffix array의 시작 index / i : [0,N-1]
//isa[i] : i-th index부터 시작하는 suffix array의 순위 (inverseSA / isa[sa[i]] = i)
int N, d, sa[MAX], isa[MAX];
int pos[MAX], temp[MAX], lcp[MAX];

bool compare(int i, int j) {	//true : i가 j보다 순위가 높다
	if(pos[i] != pos[j]) return pos[i] < pos[j];

	i += d;
	j += d;

	if(i < N && j < N) return pos[i] < pos[j];
	else return i > j;
	//suffix array에서, 시작한 index(i,j) 중 큰 것이 길이가 더 짧은 suffix array이다. 
}

void constructSA(string S) {
	N = S.length();
	for(int i = 0; i < N; ++i) {
		sa[i] = i;
		pos[i] = S[i];
	}
	for(d = 1; d<N; d *= 2) {
		//d길이의 접두사로 비교
		sort(sa,sa+N,compare);
		
		//정렬된 suffix array들 중 인접한 접미사들이 다른 그룹에 속해있으면, 전체 그룹의 수를 늘려준다
		for(int i = 0; i < N-1; ++i)
			//i+1번째 순서와 i번째 순서를 가지는(붙어있는) suffix array가 서로 다른 rank를 가지고 있으면, 
			//suffix array들이 가지고 있는 순위 그룹의 수를 증가한다 (ex) 4개 그룹 -> 5개 그룹)
			temp[i+1] = temp[i] + compare(sa[i], sa[i+1]);
		
		for(int i = 0; i < N; ++i)
			//i번째 순위를 가지는 suffix array에 그룹 번호(순위)를 갱신시켜준다
			pos[sa[i]] = temp[i];

		//그룹의 개수가 N개면 (0~N-1) 정렬 완료 (없어도 코드는 잘 돌아감)
		if(temp[N-1] == N-1)
			break;
	}	
}

void constructLCP(string S) {
	for(int i = 0; i < N; ++i) isa[sa[i]] = i;	//isa[i] : inversion of sa (i-th index부터 시작하는 suffix array의 순위)
	for(int k = 0, i = 0; i < N; ++i) {		//i는 감소하지 않는다, 모든 suffix array에 대해
		if(isa[i]) {	//0순위의 suffix array는 lcp를 가지고 있지 않다 (자신보다 높은 순위의 suffix array에 대해 구하기 때문에)
			//j = sa[isa[i]-1] : i 순위의 suffix array를 볼 때, i-1 순위를 가지는 suffix array의 시작 index
			for(int j = sa[isa[i]-1]; S[i+k] == S[j+k]; ++k);
			//i 순위의 sa와 i-1 순위의 sa는 k-1개의 공통 접두사를 가지고 있다
			//lcp[isa[i]] : i-th index부터 시작하는 sa의 lcp
			lcp[isa[i]] = (k ? k-- : 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>S>>T;

	string C = S + "$" + T;
	int n = S.length();

	constructSA(C);
	constructLCP(C);

	int maxval = -1;
	int maxidx = -1;
	for(int i = 1; i < N; ++i) {
		if(lcp[i] > maxval && (sa[i] < n && sa[i-1] > n)) {
			maxval = lcp[i];
			maxidx = i;
		}
		if(lcp[i] > maxval && (sa[i] > n && sa[i-1] < n)) {
			maxval = lcp[i];
			maxidx = i;
		}
	}

	int idx = sa[maxidx];
	string result = C.substr(idx, maxval);
	
	cout<<maxval<<'\n'<<result;

	return 0;
}