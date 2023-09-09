#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int MAX = 101010;

int N, M, K;
string S[MAX];
int cnt[MAX][4];
vector<int> ansv;
vector<int> ord;
bool visited[MAX];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>K;
    for(int i = 1; i <= N; ++i) cin>>S[i];
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < M; ++j) {
            cnt[j][S[i][j] - 'A']++;
        }
    }

    for(int i = 1; i <= N; ++i) {
        int result = 0;
        for(int j = 0; j < M; ++j) {
            result += (N - cnt[j][S[i][j]-'A']);
        }
        if(result == (N-1) * K) { ord.push_back(i); }
    }

    random_shuffle(ord.begin(), ord.end());

    for(int &i : ord) {
        // cout<<i<<" ";
        if(visited[i]) continue;
        bool isvalid = true;
        for(int j = 1; j <= N; ++j) {
            if(i == j) continue;
            int c = 0;
            for(int k = 0; k < M; ++k) if(S[i][k] != S[j][k]) c++;
            if(c != K) {
                visited[j] = true;
                isvalid = false;
            }
        }
        if(isvalid) {
            cout<<i;
            return 0;
        }
    }

}