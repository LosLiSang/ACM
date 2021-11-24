#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 110
using namespace std;

int T;
// row, column
int N, M;
long map[MAX_INPUT][MAX_INPUT];
long long dp[MAX_INPUT][MAX_INPUT];


// dp[x][y] = 
int dfs(int row, int column){
    if(dp[row][column]) return dp[row][column];
    // dp[row][column] = 0;
    int maxt = 0;
    for(int i = 0; i <= map[row][column]; i++){
        for(int j = 0; j <= map[row][column] - i; j++){
            int tr = row + i;
            int tc = column + j;
            if(tr >= N || tc >= M) continue;
            if(i || j){
                int t = dfs(tr, tc);
                maxt = (maxt + t) % 10000;
            }
        }
    }
    dp[row][column] = maxt;
    return dp[row][column];
}

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j];
            }
        }
        dp[N-1][M-1] = 1;
        dfs(0, 0);
        cout << dp[0][0] << endl;
    }
    return 0;
}