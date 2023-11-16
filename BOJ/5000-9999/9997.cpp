#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;

int N;
int ans;
int word_bit[MAX];
string S;

int BIT = (1 << 26) - 1;

void bf1(int idx, int bit) {
    if(idx == N+1) {
        if(bit == BIT) ans++;
        return;
    }
    bf1(idx+1, bit);
    bf1(idx+1, bit |= word_bit[idx]);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin>>N;

    for(int i = 1; i <= N; ++i) {
        cin>>S;
        for(auto &s : S) word_bit[i] |= (1 << (s-'a'));
    }
    
    bf1(1, 0);

    cout<<ans;

    return 0;
}