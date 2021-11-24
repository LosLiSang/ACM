#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10
using namespace std;

int N, M, T;
char war[MAX_INPUT][MAX_INPUT];
int vis[MAX_INPUT][MAX_INPUT];
int move_step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int excape = 0;
int end_x, end_y;

void dfs(int step, int x, int y){
    // cout << x << " " << y << " " << step << endl;
    if(excape) return;
    if(step == T && war[x][y] == 'D'){
        excape = 1;
        return;
    }
    if(war[x][y] == 'D') return;
    // if(abs(x - end_x) + abs(y - end_y) + step > T) return;
    for(int i = 0; i < 4; i++){
        // if(excape) return;
        vis[x][y] = 1;
        int c_x = x + move_step[i][0];
        int c_y = y + move_step[i][1];
        if(war[c_x][c_y] != 'X' && c_x >= 0 && c_y >= 0 && c_x < N && c_y < M && !vis[c_x][c_y]){
            dfs(step + 1, c_x, c_y);
        } 
        vis[x][y] = 0;
    }
}


int main(){
    while(cin >> N >> M >> T && (N || M || T)){
        string t;
        
        for(int i = 0; i < N; i++){
            cin >> t;
            for(int j = 0; j < M; j++){
                war[i][j] = t[j];
                if(war[i][j] == 'D'){
                    end_x = i;
                    end_y = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        excape = 0;
        vis[0][0] = 1;
        if((end_x + end_y - T) % 2 == 0){
            dfs(0, 0, 0);
        }
        if(excape) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}