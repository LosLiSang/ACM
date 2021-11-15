#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n, k;
int val[2001];
long long dp[2007][1007];

long long bias(long long a, long long b){
    return (a - b) * (a - b);
}


int main(){
    while(cin >> n >> k){
        for(int i = 0; i < n; i++){
            cin >> val[i + 1];
        }
        sort(val + 1, val + n + 1);
        dp[2][1] = bias(val[1], val[2]);
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i / 2; j++){
                if(j * 2 == i) dp[i][j] = dp[i-2][j-1] + bias(val[i], val[i-1]);
                else{
                    long long v1 = dp[i-2][j-1] + bias(val[i], val[i-1]);
                    long long v2 = dp[i-1][j];
                    dp[i][j] = min(v1, v2);
                }
                if(i == n && j == k) break;
            }
        }
        cout << dp[n][k] << endl;
    }
    
    return 0;
}