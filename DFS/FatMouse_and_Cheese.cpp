#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 101
using namespace std;

// 1 + 2 + 5 + 6 + 11 + 12 
// 14 + 11 + 12 = 23 + 14 = 37
int n, k;
int map[MAX_INPUT][MAX_INPUT];
// int vis[MAX_INPUT][MAX_INPUT];
int dp[MAX_INPUT][MAX_INPUT];
// 下 上 右 左
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void show(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int dfs(int row, int column){
    // show();
    // cout << endl;
    int maxt = 0;
    if(dp[row][column] > 0) return dp[row][column];
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= k; j++){
            // dp[row][column] = dp[last_row][last_column] + map[row][column];
            int row_t = row + dir[i][0] * j;             
            int column_t = column + dir[i][1] * j;
            // 越界
            // 当前大小不大于上一个
            if(row_t >= 0 && column_t >= 0 && row_t < n && column_t < n){
                if(map[row_t][column_t] > map[row][column]){
                    maxt = dfs(row_t, column_t);
                    // maxt = max(t, maxt);
                }
            }
            dp[row][column] = max(dp[row][column], maxt + map[row][column]);
        }
    }
    // dp[row][column] = maxt + map[row][column];
    return dp[row][column];
}

int main(){
    while(cin >> n >> k && (n != -1 || k != -1)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        dfs(0, 0);
        cout << dp[0][0] << endl;
        // show();
    }
    return 0;
}