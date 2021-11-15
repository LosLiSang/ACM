#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int tower[101][101];

int C, N;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    cin >> C;
    while(C--){
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= i; j++){
                cin >> tower[i][j];
            }
        }
        for(int i = N-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                tower[i][j] = max(tower[i][j] + tower[i+1][j], tower[i][j] + tower[i+1][j+1]);
            }
        }
        cout << tower[0][0] << endl;
    }
    return 0;
}