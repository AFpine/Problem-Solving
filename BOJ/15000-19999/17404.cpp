#include <bits/stdc++.h>

// 17404 RGB road 2

// update 220406

using namespace std;

static const int INF = 1e9+1;

int RGB[3][1001];
int redRGB[3][1001];
int greenRGB[3][1001];
int blueRGB[3][1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    int result = INF;

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        for(int j = 0;j<3;++j)
        {
            cin>>RGB[j][i];
            redRGB[j][i] = RGB[j][i];
            greenRGB[j][i] = RGB[j][i];
            blueRGB[j][i] = RGB[j][i];
        }
    }

    redRGB[0][2] = INF;
    greenRGB[1][2] = INF;
    blueRGB[2][2] = INF;
    for(int i = 3;i<=N;++i)
    {
        redRGB[0][i] += min(redRGB[1][i-1],redRGB[2][i-1]);
        redRGB[1][i] += min(redRGB[0][i-1],redRGB[2][i-1]);
        redRGB[2][i] += min(redRGB[0][i-1],redRGB[1][i-1]);
        greenRGB[0][i] += min(greenRGB[1][i-1],greenRGB[2][i-1]);
        greenRGB[1][i] += min(greenRGB[0][i-1],greenRGB[2][i-1]);
        greenRGB[2][i] += min(greenRGB[0][i-1],greenRGB[1][i-1]);
        blueRGB[0][i] += min(blueRGB[1][i-1],blueRGB[2][i-1]);
        blueRGB[1][i] += min(blueRGB[0][i-1],blueRGB[2][i-1]);
        blueRGB[2][i] += min(blueRGB[0][i-1],blueRGB[1][i-1]);
    }

    if(result > redRGB[1][N] + redRGB[0][1])
    {
        result = redRGB[1][N] + redRGB[0][1];
    }
    if(result > redRGB[2][N] + redRGB[0][1])
    {
        result = redRGB[2][N] + redRGB[0][1];
    }
    if(result > greenRGB[0][N] + greenRGB[1][1])
    {
        result = greenRGB[0][N] + greenRGB[1][1];
    }
    if(result > greenRGB[2][N] + greenRGB[1][1])
    {
        result = greenRGB[2][N] + greenRGB[1][1];
    }
    if(result > blueRGB[0][N] + blueRGB[2][1])
    {
        result = blueRGB[0][N] + blueRGB[2][1];
    }
    if(result > blueRGB[1][N] + blueRGB[2][1])
    {
        result = blueRGB[1][N] + blueRGB[2][1];
    }

    cout<<result<<'\n';

	return 0;
}