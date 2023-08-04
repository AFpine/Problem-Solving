#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 1010101;

int N;
unordered_map<int, int> mp;
int cnt;
int uf[MAX];
int seq[MAX], idx[MAX];
vector<int> result[MAX];

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

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    fill(uf, uf+MAX, -1);

    cin>>N;
    for(int i = 1; i <= N; ++i) {
        cin>>seq[i];
        idx[seq[i]] = i;
    }

    for(int i = 1; i <= N; ++i) {
        int cur = idx[i];
        if(cur <= i) continue;
        int t = cur - i;

        for(int j = cur-1; j >= 1; --j) {
            if(find(seq[j]) == find(i)) break;
            if(t <= 0) break;

            if(seq[j] > i) {
                merge(i, seq[j]);
                t--;
                continue;
            }
            else {
                merge(i, seq[j]);
                break;
            }
        }
    }

    for(int i = 1; i <= N; ++i) {
        int c = find(i);
        if(mp[c] == 0) mp[c] = ++cnt;
        result[mp[c]].push_back(i);
    }

    cout<<cnt<<'\n';
    for(int i = 1; i <= cnt; ++i) {
        cout<<sz(result[i])<<' ';
        for(auto &e : result[i]) cout<<e<<' ';
        cout<<'\n';
    }

	return 0;
}