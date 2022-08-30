// #define LOCAL_TEST

#include <bits/stdc++.h>

// 15644 구슬 탈출 3

// update 220830

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 1000000007;
const int MAX = 15;

int N, M;
pii H;
bool incorrect, correct, moved;
char board[MAX][MAX];
queue<pii> redQ, blueQ;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input() {
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
			if(board[i][j] == 'O') H = {i, j};
			if(board[i][j] == 'R') redQ.push({i, j});
			if(board[i][j] == 'B') blueQ.push({i, j});
		}
	}
}

pii redMove(pii cur, pii blue, pii move) {
	int x = cur.first + move.first, y = cur.second + move.second;
	while(true) {
		if(x < 1 || x > N || y < 1 || y > M) break;
		if(board[x][y] == '#') break;
		if(pii(x, y) == blue) break;		
		if(pii(x, y) == H) {
			correct = true;
			return {-1, -1};
		}
		moved = true;
		cur = {x, y};
		x += move.first;
		y += move.second;
	}
	return cur;
}

pii blueMove(pii cur, pii red, pii move) {
	int x = cur.first, y = cur.second;
	while(true) {
		if(x < 1 || x > N || y < 1 || y > M) break;
		if(board[x][y] == '#') break;
		if(pii(x, y) == red) break;
		if(pii(x, y) == H) {
			incorrect = true;
			return {-1, -1};
		}
		moved = true;
		cur = {x, y};
		x += move.first;
		y += move.second;
	}
	return cur;
}

void solve() {
	bool flag = false;
	queue<string> sQ;
	sQ.push("");
	while(!sQ.empty()) {
		auto s = sQ.front();
		sQ.pop();
		if(sz(s) >= 10) { correct = true; break; }

		auto r = redQ.front(), b = blueQ.front();
		redQ.pop(), blueQ.pop();
		
		for(int dir = 0; dir < 4; ++dir) {
			pii tr, tb;
			if(dir == 0 && r.first < b.first) {
				tr = redMove(r, b, {dx[dir], dy[dir]});
				tb = blueMove(b, tr, {dx[dir], dy[dir]});
			}
			else if(dir == 0){
				tb = blueMove(b, r, {dx[dir], dy[dir]});
				tr = redMove(r, tb, {dx[dir], dy[dir]});
			}
			else if(dir == 1 && r.first > b.first) {
				tr = redMove(r, b, {dx[dir], dy[dir]});
				tb = blueMove(b, tr, {dx[dir], dy[dir]});
			}
			else if(dir == 1){
				tb = blueMove(b, r, {dx[dir], dy[dir]});
				tr = redMove(r, tb, {dx[dir], dy[dir]});
			}
			else if(dir == 2 && r.second < b.second) {
				tr = redMove(r, b, {dx[dir], dy[dir]});
				tb = blueMove(b, tr, {dx[dir], dy[dir]});
			}
			else if(dir == 2){
				tb = blueMove(b, r, {dx[dir], dy[dir]});
				tr = redMove(r, tb, {dx[dir], dy[dir]});
			}
			else if(dir == 3 && r.second > b.second) {
				tr = redMove(r, b, {dx[dir], dy[dir]});
				tb = blueMove(b, tr, {dx[dir], dy[dir]});
			}
			else if(dir == 3){
				tb = blueMove(b, r, {dx[dir], dy[dir]});
				tr = redMove(r, tb, {dx[dir], dy[dir]});
			}

			if(incorrect) {incorrect = false; correct = false; moved = false; continue;}
			else if(correct) {
				cout<<sz(s)+1<<'\n';
				cout<<s;
				if(dir == 0) cout<<"U";
				if(dir == 1) cout<<"D";
				if(dir == 2) cout<<"L";
				if(dir == 3) cout<<"R";
				flag = true;
				break;
			}
			else if(moved) {
				char c;
				if(dir == 0) sQ.push({s+"U"});
				if(dir == 1) sQ.push({s+"D"});
				if(dir == 2) sQ.push({s+"L"});
				if(dir == 3) sQ.push({s+"R"});
				redQ.push(tr), blueQ.push(tb);
				moved = false;
			}
		}
		if(correct) break;
	}
	if(!flag) cout<<"-1";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	input();
	solve();

	return 0;
}