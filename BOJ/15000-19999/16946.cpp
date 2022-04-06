#include <bits/stdc++.h>

using namespace std;

//16946 Breaking Wall

char MAP[1001][1001];
int dist[1001][1001];
bool checkgroup[1000001];
int groupdist[1000001];
int groupnum[1001][1001];
bool visited[1001][1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int DFS(pair<int,int> cur, int num, int group, int N, int M)
{   
    groupnum[cur.first][cur.second] = group;
    for(int dir = 0;dir<4;++dir)
    {
        int x = cur.first + dx[dir];
        int y = cur.second + dy[dir];

        if(x<0 || x>=N || y<0 || y>=M)
        {
            continue;
        }
        if(visited[x][y] == false && MAP[x][y] == '0')
        {
            visited[x][y] = true;
            num = DFS({x,y},num,group, N, M);
        }
    }
    return num+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    string s;
    int group = 0;
    cin>>N>>M;

    queue<pair<int,int>> oneQ;
    queue<pair<int,int>> zeroQ;

    for(int i = 0;i<N;++i)
    {
        cin>>s;
        for(int j = 0;j<M;++j)
        {
            MAP[i][j] = s[j];
            if(MAP[i][j] == '1')
            {
                groupnum[i][j] = -1;
                oneQ.push({i,j});
            }
            else
            {
                dist[i][j] = 1;
                zeroQ.push({i,j});
            }
        }
    }

    while(!zeroQ.empty())
    {
        pair<int,int> cur = zeroQ.front();
        zeroQ.pop();
        if(visited[cur.first][cur.second] == true)
        {
            continue;
        }
        visited[cur.first][cur.second] = true;
        groupdist[group] = DFS(cur,0,group, N, M);
        group++;
    }

    while(!oneQ.empty())
    {
        pair<int,int> cur = oneQ.front();
        oneQ.pop();

        for(int i = 0;i<=group;++i)
        {
            checkgroup[i] = false;
        }

        for(int dir = 0;dir<4;++dir)
        {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];

            if(x < 0 || x >= N || y < 0 || y >= M)
            {
                continue;
            }
            if(MAP[x][y] == '0')
            {
                if(checkgroup[groupnum[x][y]] == false)
                {
                    checkgroup[groupnum[x][y]] = true;
                    dist[cur.first][cur.second] += groupdist[groupnum[x][y]];
                }
            }
        }
        dist[cur.first][cur.second] = (dist[cur.first][cur.second] + 1) % 10; 
    }
    
    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<M;++j)
        {
            if(MAP[i][j] == '0')
            {
                cout<<"0";
            }
            else
            {
                cout<<dist[i][j];
            }
        }
        cout<<'\n';
    }


	return 0;
}