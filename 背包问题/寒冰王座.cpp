#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10010
using namespace std;

int T;
int dp[MAX_INPUT];
int list[3] = {150, 200, 350};

int main(){
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        memset(dp, MIN, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < 3; i++){
            for(int j = list[i]; j <= N; j++){
                dp[j] = max(dp[j], dp[j-list[i]] + list[i]);
            }
        }
        cout << N - dp[N] << endl;
    }
    return 0;
}