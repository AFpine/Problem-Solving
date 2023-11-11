#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

const int MAX = 101010;
int N, M;
pll uf[MAX];

pll find(ll a) {
    if(uf[a].first < 0) return { a, uf[a].second };
    auto ra = find(uf[a].first);
    uf[a].first = ra.first;
    uf[a].second += ra.second;
    return uf[a];
}

void merge(ll a, ll b, ll w) {
    auto ra = find(a);
    auto rb = find(b);
    if(ra.first == rb.first) return;

    uf[ra.first].first = rb.first;
    uf[ra.first].second = rb.second - ra.second + w;
}

void solve() {
    for(int i = 0; i < MAX; ++i) {
        uf[i].first = -1;
        uf[i].second = 0;
    }

    for(int i = 1; i <= M; ++i) {
        char c;
        ll a, b, w;
        cin>>c;
        if(c == '!') {
            cin>>a>>b>>w;
            merge(a, b, w);
        }
        else {
            cin>>a>>b;
            if(find(a).first != find(b).first) cout<<"UNKNOWN\n";
            else cout<<-(find(b).second - find(a).second)<<"\n";
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    while(true) {
        cin>>N>>M;
        if(N == 0 && M == 0) break;
        solve();
    }

    return 0;
}