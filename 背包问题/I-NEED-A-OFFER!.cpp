#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;

int money, m;

struct data{
    int cost;
    double val;
}list[10010];

double dp[10010];

int main(){
    while(cin >> money >> m && (money || m)){
        for(int i = 0; i < m; i++){
            cin >> list[i+1].cost >> list[i+1].val;
        }
        for(int i = 0; i <= money; i++)
            dp[i] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = money; j >= list[i].cost; j--){
                dp[j] = min(dp[j], dp[j-list[i].cost] * (1 - list[i].val));
            }
            // cout << dp[1] << " " << dp[2] << " " << dp[3] << " " << dp[4] << " " << dp[5] << " " <<
            // dp[6] << " " << dp[7] << " " << dp[8] << " " << dp[9] << " " << dp[10] << " " << endl;
        }
        printf("%.1lf", (1-dp[money]) * 100);
        cout << "%" << endl;
    };
    return 0;
}