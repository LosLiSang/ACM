#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int T, N, V;
int Volume[1001];
int Value[1001];
// 前i个物品，j个空间物品的最大价值 
// dp[i][k] = max(dp[i-1][k], dp[i-1][k-Volume[i]] + Value[i])
long long dp[1001][1001];
int main(){
    cin >> T;
    while(T--){
        cin >> N >> V;
        for(int i = 0; i < N; i++)
            cin >> Value[i+1];
        for(int i = 0; i < N; i++)
            cin >> Volume[i+1];
        for(int i = 1; i <= N; i++){
            for(int j = 0; j <= V; j++){
                long long value2 = 0, value1 = 0;
                value1 = dp[i-1][j];
                if(j >= Volume[i])
                    value2 = dp[i-1][j - Volume[i]] + Value[i];
                dp[i][j] = max(value1, value2);
            }
        }
        cout << dp[N][V] << endl;
    }
    return 0;
}