#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 100100
using namespace std;

int N;

struct{
    int count;
    int val;
}list[MAX_INPUT];

int dp[MAX_INPUT];

int main(){
    while(cin >> N && N != -1){
        int all = N, allVal = 0;
        for(int i = 1; i <= N; i++){
            cin >> list[i].val >> list[i].count;
            allVal += list[i].val * list[i].count;
            for(int j = 1; list[i].count > j; j *= 2){
                list[i].count -= j;
                list[all+1].count = j;
                list[all+1].val = list[i].val;
                all++;
            }
        }
        int Weight = allVal / 2;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= all; i++){
            for(int j = Weight; j >= list[i].count * list[i].val; j--){
                dp[j] = max(dp[j], dp[j-list[i].count * list[i].val] + list[i].count * list[i].val);
            }
            for(int j = 0; j <= Weight; j++){
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        cout << allVal - dp[Weight] << " " << dp[Weight] << endl;
    }
    return 0;
}