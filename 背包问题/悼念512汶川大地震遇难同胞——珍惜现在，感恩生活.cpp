#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 0x3f3f3f3f
#define MAX_INPUT 10010
// m：
// n: Money
int C, m, n;
struct{
    int count;
    int weight;
    int val;
}list[MAX_INPUT];

int dp[MAX_INPUT];

int main(){
    cin >> C;
    while(C--){
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        int all = m;
        for(int i = 1; i <= m; i++){
            cin >> list[i].weight >> list[i].val >> list[i].count;
            for(int j = 1; list[i].count > j; j *= 2){
                list[i].count -= j;
                list[all+1].count = j;
                list[all+1].weight = list[i].weight;
                list[all+1].val = list[i].val;
                all++;
            }
        }
        // cout << endl;
        for(int i = 1; i <= all; i++){
            // cout << list[i].weight << " " << list[i].val << " " << list[i].count << endl;
            for(int j = n; j >= list[i].weight * list[i].count; j--){
                dp[j] = max(dp[j], dp[j - (list[i].weight * list[i].count)] + (list[i].val * list[i].count));
            }
            // for(int i = 0; i <= n; i++){
            //     cout << dp[i] << " ";
            // }
            // cout << endl;
        }
        cout << dp[n] << endl;
    }
    return 0;
}