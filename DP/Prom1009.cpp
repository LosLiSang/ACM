#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, k;
int dp[30][520], loc[30][20];

int abs(int x)
{
    return x < 0 ? -x : x;
}

int main()
{

    //freopen("input.txt","r",stdin);

    while (~scanf("%d%d", &n, &k)){
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 500; j++)
                dp[i][j] = INF;
        for (int j = 1; j <= k; j++){
            scanf("%d", &loc[1][j]);
            dp[1][loc[1][j]] = 0;
        }
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= k; j++){
                scanf("%d", &loc[i][j]);
                for (int x = 1; x <= k; x++)
                {
                    int tmp = dp[i - 1][loc[i - 1][x]] + abs(loc[i][j] - loc[i - 1][x]);
                    if (dp[i][loc[i][j]] > tmp)
                        dp[i][loc[i][j]] = tmp;
                }
            }
        int ans = INF;
        for (int i = 1; i <= 500; i++)
            if (dp[n][i] < ans)
                ans = dp[n][i];
        printf("%d\n", ans);
    }
    return 0;
}