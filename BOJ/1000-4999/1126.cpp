#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
int arr[55];
int dp[55][1010101];

int f(int idx, int hd) {
    if(idx == 0) {
        if(hd == 0) return 0;
        else return -1000000000;
    }
    
    auto &ret = dp[idx][hd];
    if(ret != -1) return ret;

    ret = -1000000000;

    ret = max(ret, f(idx-1, hd));
    ret = max(ret, f(idx-1, hd + arr[idx]));

    if(arr[idx] >= hd) ret = max(ret, f(idx-1, arr[idx] - hd) + hd);
    else ret = max(ret, f(idx-1, hd - arr[idx]) + arr[idx]);

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp, -1, sizeof(dp));

    cin>>N;

    for(int i = 1; i <= N; ++i) cin>>arr[i];

    auto ans = f(N, 0);
    
    if(ans <= 0) cout<<"-1";
    else cout<<ans;

    return 0;
}