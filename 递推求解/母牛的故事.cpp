#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
long long cow[56]; // 第n年的可生育的母牛数，也是小牛数
long long sum[56];

int main(){
    sum[1] = 1;
    sum[2] = 2;
    sum[3] = 3;
    sum[4] = 4;
    cow[1] = 1;
    cow[2] = 1;
    cow[3] = 1;
    cow[4] = 1;
    for(int i = 5; i < 56; i++){
        // cow[i] = cow[i-1] + cow[i-3];
        sum[i] = sum[i-1] + sum[i-3];
    }

    while(cin >> n && n){
        cout << sum[n] << endl;
    }
    return 0;
}