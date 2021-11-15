#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 1100
using namespace std;

int Need, Weight, N, Count;
int e[MAX_INPUT];
int w[MAX_INPUT];
int dp[MAX_INPUT][MAX_INPUT]; // dp[i][j] 表示，杀i个怪，获得j点经验的剩余最大忍耐度

// dp[i][j] = max{dp[i][j], dp[i-1][j]}

int main(){
    while(cin >> Need >> Weight >> N >> Count){
        for(int i = 1; i <= N; i++){
            cin >> e[i] >> w[i];
        }
        memset(dp, MAX, sizeof(dp));
        memset(dp[0], MAX, sizeof(dp[0]));
        for(int i = 0; i <= Count; i++) dp[i][0] = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= Count; j++){
                for(int k = e[i]; k <= Need; k++){
                    dp[j][k] = min(dp[j][k], dp[j-1][k-e[i]] + w[i]);
                }
            }
        }
        
        // cout << Weight - dp[Count][Need] << endl;
        if(dp[Count][Need] == MAX)
            cout << -1 << endl;
        else 
            cout << Weight - dp[Count][Need] << endl;
    }
    return 0;
}