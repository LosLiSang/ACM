#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 20
using namespace std;

char map[MAX_INPUT][MAX_INPUT];
int vis[MAX_INPUT][MAX_INPUT];
int M, N;
int start;

void dfs(int x, int y, int step){
    // cout << x << " " << y << " " << step << endl;
    if(x <= 0 || y <= 0 || x > M || y > N){
        // 离开
        // cout << step << endl;
        printf("%d step(s) to exit\n", step);
        return;
    }
    if(vis[x][y]){
        // 重复
        printf("%d step(s) before a loop of %d step(s)\n", vis[x][y], step - vis[x][y]);
        // cout << vis[x][y] << " " << step - vis[x][y] << endl;
        return;
    }
    if(map[x][y] == 'W'){
        // 左
        vis[x][y] = step;
        dfs(x, y - 1, step + 1);
        // vis[x][y] = 0;
    }else if(map[x][y] == 'E'){
        // 右
        vis[x][y] = step;
        dfs(x, y + 1, step + 1);
        // vis[x][y] = 0;
    }else if(map[x][y] == 'N'){
        // 上
        vis[x][y] = step;
        dfs(x - 1, y, step + 1);
        // vis[x][y] = 0;
    }else if(map[x][y] == 'S'){
        // 下 
        vis[x][y] = step;
        dfs(x + 1, y, step + 1);
        // vis[x][y] = 0;
    }    
} 

int main(){
    while(scanf("%d%d%d", &M, &N, &start ) && M && N && start){
        // cin >> start;
        for(int i = 0; i < M; i++){
            string T;
            cin >> T;
            for(int j = 0; j < N; j++){
                map[i + 1][j + 1] = T[j];
            }
        }
        memset(vis, 0, sizeof(vis));
        vis[1][start] = 1;
        dfs(1, start, 1);
    }
    return 0;
}