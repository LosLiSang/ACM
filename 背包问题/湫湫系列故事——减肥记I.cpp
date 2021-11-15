#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 100100
using namespace std;

int N;
int val[MAX_INPUT];
int weight[MAX_INPUT];
int dp[MAX_INPUT];

int main(){
    while(cin >> N){
        for(int i = 1; i <= N; i++)
            cin >> val[i] >> weight[i];
        int th;
        cin >> th;
        memset(dp, MIN, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= N; i++){
            for(int j = weight[i]; j <= th; j++){
                dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);
            }
        }
        cout << dp[th] << endl;
    }
    return 0;
}