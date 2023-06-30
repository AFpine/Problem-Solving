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
const int MAX = 50505;

int N;
int fail[MAX];
string A, W, S;
unordered_map<char, int> mp;
char mp2[70];
vector<int> result;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    while(N--) {
        fill(fail, fail+MAX, 0);
        mp.clear();
        result.clear();

        cin>>A>>W>>S;
        int a = A.length();
        int w = W.length();
        int s = S.length();

        int cnt = 0;
        for(int i = 0; i < a; ++i) {
            mp[A[i]] = cnt;
            mp2[cnt] = A[i];
            cnt++;
        }

        for(int i = 1, j = 0; i < w; ++i) {
            while(j > 0 && W[i] != W[j]) j = fail[j-1];
            if(W[i] == W[j]) fail[i] = ++j;
        }

        string T = S;
        int t = T.length();
        for(int k = 0; k < a; ++k) {
            int flag = 0;
            for(int i = 0; i < t; ++i) T[i] = mp2[(mp[S[i]] - k + a) % (a)];

            for(int i = 0, j = 0; i < t; ++i) {
                while(j > 0 && T[i] != W[j]) j = fail[j-1];
                if(T[i] == W[j]) {
                    if(j == (w-1)) {
                        flag++;
                        j = fail[j];
                    }
                    else ++j;
                }
            }
            if(flag == 1) result.push_back(k);
        }

        if(result.empty()) {
            cout<<"no solution\n";
        }
        else if(result.size() == 1) {
            cout<<"unique: "<<result[0]<<'\n';
        }
        else {
            cout<<"ambiguous: ";
            for(auto &i : result) cout<<i<<" ";
            cout<<'\n';
        }

    }
    

	return 0;
}