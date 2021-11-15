#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAX 0x3f3f3f3f

int T;
int weight[10010];
int val[10010];
int dp[1001000];

int main(){
    cin >> T;
    while(T--){
        int E, F, N;
        cin >> E >> F;
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> val[i] >> weight[i];
        }
        int totalWeight = F - E;
        dp[0] = 0;
        for(int i = 1; i <= totalWeight; i++){
            dp[i] = MAX;
        }
        for(int i = 1; i <= N; i++){
            for(int j = weight[i]; j <= totalWeight; j++){
                // if(j >= weight[i])
                    dp[j] = min(dp[j], dp[j-weight[i]] + val[i]);
            }
            // for(int k = 0; k <= totalWeight; k++){
            //     cout << dp[k] << " ";
            // }
            // cout << endl;
        }
        if(dp[totalWeight] == MAX)
            cout << "This is impossible." << endl;
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[totalWeight]);

    }
    return 0;
}