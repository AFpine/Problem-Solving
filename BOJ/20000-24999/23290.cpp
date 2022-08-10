#include <bits/stdc++.h>

// 23290 마법사 상어와 복제

// update 220810

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAX = 1000005;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int sdx[4] = {-1, 0, 1, 0};
int sdy[4] = {0, -1, 0, 1};

int M, S;
pii shark;
vector<pair<pii, int>> fish;
vector<int> sharkPath;
int fishsmell[10][10];
int fishes[10][10];
bool eated[10][10];
int maxv;
int curTime;

void input() {
	cin>>M>>S;
	for(int i = 1; i <= M; ++i) {
		int x, y, m;
		cin>>x>>y>>m;
		fish.push_back({{x, y}, m-1});
	}
	cin>>shark.first>>shark.second;
}

void smellinit() {
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= 4; ++j) if(fishsmell[i][j] > 0) fishsmell[i][j]--;
	}
}

vector<pair<pii, int>> fishMove() {
	vector<pair<pii, int>> ret;
	for(auto &f : fish) {
		bool flag = false;
		auto cur = f.first;
		auto direc = f.second;
		for(int dir = 0; dir < 8; ++dir) {
			int curdirec = (direc-dir+8) % 8;
			int x = cur.first + dx[curdirec];
			int y = cur.second + dy[curdirec];

			if(x < 1 || x > 4 || y < 1 || y > 4) continue;
			if(pii(x, y) == shark) continue;
			if(fishsmell[x][y] > 0) continue;
			// if(fishsmell[x][y] != 0 && curTime - fishsmell[x][y] <= 2) continue;

			ret.push_back({{x, y}, curdirec});
			flag = true;
			break;
		}
		if(!flag) ret.push_back(f);
	}
	return ret;
}

int MoveShark(vector<int> &V) {
	bool visited[10][10] = {false};
	int ret = 0;
	int x = shark.first, y = shark.second;
	for(auto &dir : V) {
		x += sdx[dir];
		y += sdy[dir];
		if(x < 1 || x > 4 || y < 1 || y > 4) return -1;
		if(!visited[x][y]) {
			visited[x][y] = true;
			ret += fishes[x][y];
		}
	}
	return ret;
}

void backtracking(vector<int> &V) {
	if(sz(V) == 3) {
		int temp = MoveShark(V);
		if(maxv < temp) {
			maxv = temp;
			sharkPath = V;
		}
		return;
	}
	for(int dir = 0; dir < 4; ++dir) {
		V.push_back(dir);
		backtracking(V);
		V.pop_back();
	}
}

void realMoveShark() {
	for(auto dir : sharkPath) {
		shark.first += sdx[dir];
		shark.second += sdy[dir];
		if(fishes[shark.first][shark.second] > 0) {
			eated[shark.first][shark.second] = true;
			fishsmell[shark.first][shark.second] = 3;
		}
	}
}

void sharkMove() {
	maxv = -1;
	sharkPath.clear();
	memset(eated, false, sizeof(eated));
	vector<int> tempV;
	backtracking(tempV);
	realMoveShark();
}

void solve() {
	for(int s = 1; s <= S; ++s) {
		curTime++;
		memset(fishes, 0, sizeof(fishes));
		auto tempfish = fish;

		fish = fishMove();
		for(auto &f : fish) fishes[f.first.first][f.first.second]++;

		sharkMove();
		smellinit();

		vector<pair<pii, int>> nextfish;
		for(auto &f : fish) {
			if(eated[f.first.first][f.first.second]) continue;
			nextfish.push_back(f);
		}
		for(auto &f : tempfish) {
			nextfish.push_back(f);
		}
		fish = nextfish;
	}

	int result = sz(fish);
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}