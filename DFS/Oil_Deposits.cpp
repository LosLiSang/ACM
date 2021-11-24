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

int rows, columns;
char map[MAX_INPUT][MAX_INPUT];
int vis[MAX_INPUT][MAX_INPUT];
int dir[8][2] = {{1, 0}, {1, 1}, {0, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, -1}};

void dfs(int row, int column){
    // cout << row << " " << column << endl;
    if(row < 0 || column < 0 || row >= rows || column >= columns){
        return;
    }
    // !vis[row][column] ||
    if(map[row][column] == '*'){
        // vis[row][column] = 1;
        return;
    }
    // vis[row][column] = 1;
    map[row][column] = '*';
    for(int i = 0; i < 8; i++){
        dfs(row + dir[i][0], column + dir[i][1]);
    }
}

int main(){
    while(cin >> rows >> columns && (rows || columns)){
        for(int i = 0; i < rows; i++){
            string s;
            cin >> s;
            for(int j = 0; j < columns; j++){
                map[i][j] = s[j];
            }
        }
        memset(vis, 0, sizeof(vis));
        int size = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                // !vis[i][j] &&
                if(map[i][j] != '*'){
                    // cout << i << " " << j << endl;
                    dfs(i, j);
                    size++;
                }
            }
        }
        cout << size << endl;
    }
    return 0;
}