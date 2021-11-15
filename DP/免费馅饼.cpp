#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
int list[100001][11];

int max(int n, int b){
    return n > b ? n : b;
}

int max_3(int a, int b, int c){
    int max = a;
    max = max > b ? max : b;
    max = max > c ? max : c;
    return max;
}

int main(){
    while(scanf("%d", &n) && n){
        for(int i = 0; i < 100001; i++){
            for(int j = 0; j < 11; j++){
                list[i][j] = 0;
            }
        }
        int x, T, maxT = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &T);
            maxT = max(maxT, T);
            list[T][x] += 1;
        }
        for(int i = maxT-1; i >= 0; i--){
            for(int j = 0; j < 11; j++){
                if(j == 0){
                    list[i][j] = max(list[i][j] + list[i+1][j], list[i][j] + list[i+1][j+1]);
                    // cout << list[i][j] << " " << j << " " << i << endl;
                }
                else if(j == 10)
                    list[i][j] = max(list[i][j] + list[i+1][j], list[i][j] + list[i+1][j-1]);
                else
                    list[i][j] = max_3(list[i][j] + list[i+1][j], list[i][j] + list[i+1][j+1], list[i][j] + list[i+1][j-1]);
                // cout << list[i][j] << " " << j << " " << i << endl;
            }
        }
        cout << list[0][5] << endl;
    }
    return 0;
}