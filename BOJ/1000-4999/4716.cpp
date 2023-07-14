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
const long long MOD = 1e9+7;
const int MAX = 1010;

struct balloon {
	int K, Da, Db;
};

int N, A, B;
balloon arr[MAX];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true) {
		cin>>N>>A>>B;
		if(N == 0 && A == 0 && B == 0) break;

		int result = 0, curA = 0, curB = 0;

		for(int i = 1; i <= N; ++i) {
			cin>>arr[i].K>>arr[i].Da>>arr[i].Db;
		}

		sort(arr+1, arr+1+N, [](balloon a, balloon b) {
			return abs(a.Da - a.Db) > abs(b.Da - b.Db);
		});

		for(int i = 1; i <= N; ++i) {
			if(arr[i].Da < arr[i].Db) {
				if(curA + arr[i].K <= A) {
					curA += arr[i].K;
					result += (arr[i].K * arr[i].Da);
				}
				else {
					int t = A - curA;
					curA = A;
					curB += (arr[i].K - t);
					result += (arr[i].Da * t) + (arr[i].Db * (arr[i].K - t));
				}
			}
			else {
				if(curB + arr[i].K <= B) {
					curB += arr[i].K;
					result += (arr[i].K * arr[i].Db);
				}
				else {
					int t = B - curB;
					curB = B;
					curA += (arr[i].K - t);
					result += (arr[i].Db * t) + (arr[i].Da * (arr[i].K - t));
				}
			}
		}

		cout<<result<<'\n';
	}
	
	return 0;
}