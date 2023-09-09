#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<double, double> pdd;

const int MAX = 2020;
const int INF = 1e9+5;

struct Frac {
    ll n, d1, d2, d;
    int p, q;
    bool operator<(const Frac& rhs) const {
        if(n*rhs.d == rhs.n*d) {
            return max(p, q) < max(rhs.p, rhs.q);
        }
        return n*rhs.d > rhs.n*d;
    }
    // bool operator==(const Frac& rhs) const {
    //     return n*rhs.d == rhs.n*d;
    // }
    // bool operator<=(const Frac& rhs) const {
    //     return n*rhs.d >= rhs.n*d;
    // }
    Frac operator+(const Frac& rhs) const {
        Frac ret;
        ret.n = n + rhs.n;
        ret.d1 = d1 + d2;
        ret.d2 = rhs.d1 + rhs.d2;
        ret.d = ret.d1 * ret.d2;
        return ret;
    }
};

int N;
pll star[MAX];
Frac arr[MAX*2];
ll dist[MAX*2][MAX*2];

priority_queue<Frac> pq;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for(int i = 1; i <= N; ++i) {
        cin>>star[i].first>>star[i].second;
        arr[i].n = 0;
        arr[i].d = 1;
        arr[i].d1 = 1;
        arr[i].d2 = 0;

    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            dist[i][j] = (star[i].first - star[j].first) * (star[i].first - star[j].first) + 
            (star[i].second - star[j].second) * (star[i].second - star[j].second);

            pq.push({dist[i][j], 1, 1, 1, i, j});
        }
    }

    int flag = N+1;

    unordered_set<int> S;
    for(int i = 1; i <= N; ++i) S.insert(i);
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(!S.count(cur.p) || !S.count(cur.q)) continue;
        S.erase(cur.p);
        S.erase(cur.q);

        for(auto &i : S) {
            Frac res;
            dist[i][flag] = dist[i][cur.p] + dist[i][cur.q];
            dist[flag][i] = dist[i][cur.p] + dist[i][cur.q];

            res = arr[i] + cur;
            res.n = dist[i][flag];
            res.p = i;
            res.q = flag;
            pq.push(res);
        }

        S.insert(flag);

        cout<<cur.d1+cur.d2<<"\n";
        arr[flag] = cur;
        flag++;
    }

    return 0;
}