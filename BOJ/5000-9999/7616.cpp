#include <bits/stdc++.h>

// 7616 교실로 가는 길

// update 220526

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 5005;

int T;
int K,N;
vector<int> adj[MAX];
bool c[MAX][MAX], f[MAX][MAX], visited[MAX];
bool tmp[MAX];
bool chk[MAX], adjChk[MAX];
vector<int> path;

void init()
{
    path.clear();
    for(int i = 0;i<MAX;++i)
    {
        adj[i].clear();
        visited[i] = false;
        tmp[i] = false;
        chk[i] = false;
        adjChk[i] = false;
        for(int j = 0;j<MAX;++j)
        {
            c[i][j] = 0;
            f[i][j] = 0;
        }
    }
}

int main()
{ 
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

    while(true)
    {
        init();
        T++;
        scanf("%d %d", &K, &N);
        if(K == 0 && N == 0)
        {
            break;
        }

        for(int i = 1;i<=N;++i)
        {
            memset(adjChk, false, sizeof(adjChk));
            vector<int> tempV;
            char tempC;
            int tempI;
            while(true)
            {
                scanf("%d%c", &tempI, &tempC);
                
                if(chk[i] == false)
                {
                    chk[i] = true;
                }   
                if(chk[tempI] == false)
                {
                    if(adjChk[tempI] == false)
                    {
                        adjChk[tempI] = true;
                        c[i][tempI] = 1;
                        c[tempI][i] = 1;

                        adj[i].push_back(tempI);
                        adj[tempI].push_back(i);
                    }
                }

                if(tempC == '\n')
                {
                    break;
                }
            }
        }

        int totalFlow = 0;
        int S = 1, E = 2;
        while(true)
        {
            int prev[MAX];
            queue<int> Q;
            fill(prev,prev+MAX,-1);
            Q.push(S);

            while(!Q.empty())
            {
                int cur = Q.front();
                Q.pop();
                
                if(cur != S && cur != E)
                {
                    visited[cur] = true;
                }

                for(auto &next : adj[cur])
                {
                    if(next == S || visited[next] == true)
                    {
                        continue;
                    }
                    if(prev[next] == -1 && c[cur][next] - f[cur][next] > 0)
                    {
                        prev[next] = cur;
                        Q.push(next);
                        if(next == E)
                        {
                            break;
                        }
                    }
                }
            }

            memset(visited,false,sizeof(visited));

            if(prev[E] == -1)
            {
                break;
            }

            memcpy(visited,tmp,sizeof(tmp));

            for(int i = E; i != S; i = prev[i])
            {
                path.push_back(i);
                f[prev[i]][i] = 1;
                f[i][prev[i]] = 0;

                if(i != S && i != E)
                {
                    visited[i] = true;
                }
            }
            memcpy(tmp,visited,sizeof(visited));

            path.push_back(S);

            totalFlow += 1;
        }

        printf("Case %d:\n",T);
        if(totalFlow >= K)
        {
            int k = 0;
            for(int i = path.size()-1; i >= 0; --i)
            {
                if(path[i] == 2)
                {
                    printf("%d\n", path[i]);
                    k++;
                }
                else
                {
                    printf("%d ", path[i]);
                }
                if(k == K)
                {
                    break;
                }
            }
        }
        else
        {
            printf("Impossible\n");
        }
        printf("\n");
    }
	
	return 0;
}

