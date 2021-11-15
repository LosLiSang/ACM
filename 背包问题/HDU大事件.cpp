#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
#define MAX_INPUT 50010
using namespace std;

int N;

struct{
    int count;
    int val;
}list[MAX_INPUT];

int dp[MAX_INPUT];
int main(){
    while(cin >> N && N != -1){
        int all = N;
        for(int i = 1; i <= N; i++){
            cin >> list[i].val >> list[i].count;
            for(int j = 1; list[i].count > j; j *= 2){
                list[i].count -= j;
                list[all+1].count = j;
                list[all+1].val = list[i].val;
            }
        }
        dp[1] = list[i].val;
        for(int i = 1; i <= all; i++){
            // for(int j = 2; j <= list[i].count; j++){
                dp[i] = min(abs(dp[i-1] + list[i].val * list[i].count), abs(dp[j-]);
            }
        }
    }
    return 0;
}