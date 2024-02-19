#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, K;
ll len[5];
ll sum;
priority_queue<ll> pq[5];
vector<pair<char, ll>> ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>N>>K;

    for(int i = 0; i < 4; ++i) {
        cin>>len[i];
        sum += len[i];
    }

    for(int i = 1; i <= N; ++i) {
        char c;
        ll x;
        cin>>c>>x;
        pq[c - 'A'].push(x);
    }

    for(int i = 1; i <= K; ++i) {
        double mx = -1;
        int idx = -1;
        for(int j = 0; j < 4; ++j) {
            if(pq[j].empty()) continue;

            if(((double)pq[j].top() / (double)len[j]) > mx) {
                mx = ((double)pq[j].top() / (double)len[j]);
                idx = j;
            }
        }

        ans.push_back({ 'A' + idx, pq[idx].top() });
        sum += pq[idx].top();
        len[idx] += pq[idx].top();

        pq[idx].pop();
    }

    for(auto &p : ans) {
        cout<<p.first<<" "<<p.second<<'\n';
    }

    return 0;
}