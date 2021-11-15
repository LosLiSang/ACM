#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int k, n;
int list[1000][1000];
int res[1000][1000];


int main(){
    while(cin >> k >> n){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){
                cin >> list[i][j];
                res[i][j] = 0;
            }
        }
        for(int i = k-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int minBias = INT16_MAX;
                for(int m = 0; m < n; m++){
                    int temp = res[i+1][m] + abs(list[i][j] - list[i+1][m]);
                    minBias = minBias < temp ? minBias : temp;
                }
                res[i][j] =  minBias;
            }
        }
        int minRes = INT16_MAX;
        for(int i = 0; i < n; i++){
            minRes = minRes < res[0][i] ? minRes : res[0][i];
        }
        cout << minRes << endl;
    }
    return 0;
}