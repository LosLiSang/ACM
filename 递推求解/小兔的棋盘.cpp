#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
long long res[36][36];

int main(){
    // res[1][0] = 1;
    // res[0][1] = 1;
    // res[0][0] = 0;
    for(int i = 1; i < 36; i++){
        res[i][0] = 1;
        for(int j = 1; j < i; j++){
            res[i][j] = res[i-1][j] + res[i][j-1];
        }
        res[i][i] = res[i][i-1];
    }
    int i = 1;
    while(cin >> n && n != -1){
        cout << i++ << " " << n << " "  << res[n][n] * 2 << endl;
    }
    return 0;
}