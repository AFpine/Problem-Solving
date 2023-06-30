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
const long long MOD = 1e9+9;
const int MAX = 202020;

int N;
int fail[MAX];
vector<int> a, b, S, P;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    a.resize(N);
    b.resize(N);
    for(int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    for(int i = 0; i < N; ++i) {
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < N-1; ++i) {
        S.push_back(a[i+1] - a[i]);
        P.push_back(b[i+1] - b[i]);
    }
    S.push_back(a[0] - a[N-1] + 360000);
    P.push_back(b[0] - b[N-1] + 360000);

    for(int i = 0; i < N; ++i) {
        S.push_back(S[i]);
    }

    for(int i = 1, j = 0; i < N; ++i) {
        while(j > 0 && P[i] != P[j]) j = fail[j-1];
        if(P[i] == P[j]) fail[i] = ++j;
    }

    int result = 0;
    for(int i = 0, j = 0; i < 2*N; ++i) {
        while(j > 0 && S[i] != P[j]) j = fail[j-1];
        if(S[i] == P[j]) {
            if(j == N-1) {
                result++;
                j = fail[j];
            }
            else ++j;
        }
    }

    if(result > 0) cout<<"possible";
    else cout<<"impossible";

	return 0;
}