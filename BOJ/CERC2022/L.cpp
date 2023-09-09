#include <bits/stdc++.h>

using namespace std;

const int MAX = 111;
const int INF = 1e9+5;

int deck[MAX];
vector<int> hand;
vector<int> row[5];
bool finish = false;
vector<int> prv;
vector<int> remain;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 1; i <= 98; ++i) {
        cin>>deck[i];
    }
    row[1].push_back(1);
    row[2].push_back(1);
    row[3].push_back(100);
    row[4].push_back(100);

    for(int i = 1; i <= 6; ++i) {
        hand.push_back(deck[i]);
    }

    for(int k = 8; k <= 99; ++k) {
        if(k % 2 == 0) {
            hand.push_back(deck[k-1]);
            hand.push_back(deck[k]);
        }

        bool backward = false;
        int mx = INF;
        int handidx = -1;
        int rowidx = -1;

        for(int i = 0; i < hand.size(); ++i) {
            for(int j = 1; j <= 4; ++j) {
                if(backward) continue;
                if((j == 1 || j == 2) && (row[j].back() - hand[i]) == 10) {
                    backward = true;
                    handidx = i;
                    rowidx = j;
                }
                else if ((j == 3 || j == 4) && (hand[i] - row[j].back()) == 10) {
                    backward = true;
                    handidx = i;
                    rowidx = j;
                }
                else if((j == 1 || j == 2) && (row[j].back() < hand[i]) && (mx > abs(row[j].back() - hand[i]))) {
                    mx = abs(row[j].back() - hand[i]);
                    handidx = i;
                    rowidx = j;
                }
                else if((j == 3 || j == 4) && (row[j].back() > hand[i]) && (mx > abs(row[j].back() - hand[i]))) {
                    mx = abs(row[j].back() - hand[i]);
                    handidx = i;
                    rowidx = j;
                }
            }
        }

        if(handidx == -1 && rowidx == -1) {
            finish = true;
            if(k % 2) for(int j = k; j <= 98; ++j) remain.push_back(deck[j]);
            else for(int j = k + 1; j <= 98; ++j) remain.push_back(deck[j]);
            break;
        }

        row[rowidx].push_back(hand[handidx]);
        
        prv.clear();
        for(int i = 0; i < hand.size(); ++i) {
            if(i == handidx) continue;
            prv.push_back(hand[i]);
        }
        hand.clear();
        for(auto &i : prv) hand.push_back(i);
    }
    while(!finish && !hand.empty()) {
        bool backward = false;
        int mx = INF;
        int handidx = -1;
        int rowidx = -1;

        for(int i = 0; i < hand.size(); ++i) {
            for(int j = 1; j <= 4; ++j) {
                if(backward) continue;
                if((j == 1 || j == 2) && (row[j].back() - hand[i]) == 10) {
                    backward = true;
                    handidx = i;
                    rowidx = j;
                }
                else if ((j == 3 || j == 4) && (hand[i] - row[j].back()) == 10) {
                    backward = true;
                    handidx = i;
                    rowidx = j;
                }
                else if((j == 1 || j == 2) && (row[j].back() < hand[i]) && (mx > abs(row[j].back() - hand[i]))) {
                    mx = abs(row[j].back() - hand[i]);
                    handidx = i;
                    rowidx = j;
                }
                else if((j == 3 || j == 4) && (row[j].back() > hand[i]) && (mx > abs(row[j].back() - hand[i]))) {
                    mx = abs(row[j].back() - hand[i]);
                    handidx = i;
                    rowidx = j;
                }
            }
        }

        if(handidx == -1 && rowidx == -1) {
            break;
        }
        
        row[rowidx].push_back(hand[handidx]);
        
        prv.clear();
        for(int i = 0; i < hand.size(); ++i) {
            if(i == handidx) continue;
            prv.push_back(hand[i]);
        }
        hand.clear();
        for(auto &i : prv) hand.push_back(i);
    }

    for(int i = 1; i <= 4; ++i) {
        for(auto &e : row[i]) cout<<e<<" ";
        cout<<'\n';
    }
    for(auto &e : hand) cout<<e<<" ";
    cout<<'\n';
    for(auto &e : remain) cout<<e<<" ";
    cout<<'\n';

    return 0;
}