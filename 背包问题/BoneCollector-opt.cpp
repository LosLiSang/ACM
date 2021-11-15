#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int T, N, V;
int Volume[1001];
int Value[1001];
// 前i个物品，j个空间物品的最大价值 
// dp[i][k] = max(dp[i-1][k], dp[i-1][k-Volume[i]] + Value[i])
long long dp[1001];
int main(){
    cin >> T;
    while(T--){
        cin >> N >> V;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++)
            cin >> Value[i+1];
        for(int i = 0; i < N; i++)
            cin >> Volume[i+1];
        for(int i = 1; i <= N; i++){
            // for(int j = 1; j <= V; j++){
            for(int j = V; j >= 1; j--){
                long long value2 = 0, value1 = 0;
                value1 = dp[j];
                if(j >= Volume[i])
                    value2 = dp[j - Volume[i]] + Value[i];
                dp[j] = max(value1, value2);
            }
            // cout << dp[0] << " " <<  dp[1] << " " << dp[2] << " " << dp[3] << " " << dp[4] << " " << dp[5] 
            // << " " << dp[6] << " " << dp[7] << " " << dp[8] << " " << dp[9] << " " << dp[10] << endl;
        }
        cout << dp[V] << endl;
    }
    return 0;
}