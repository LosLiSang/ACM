#include<iostream>
#include<math.h>
using namespace std;

// 二分加速(快速幂)
// 改进的暴力算法
int power(int a, int b){
    if(b == 0) return 1;
    // if(b == 1) return a;
    // 如果b是基数
    if (b & 1)
        return a * power(a*a % 1000 , b>>1) % 1000;
    else
        return power(a*a % 1000, b>>1) % 1000;
}


int power_2(int a, int b){
    int res = 1;
    while(b != 1){
        if(b & 1)
            res = res * a % 1000;
        a = a * a % 1000;
        b /= 2;
    }
    return res * a;
    
}


int main(){
    int a, b;


    while(cin >> a && cin >> b){
        if(a == 0 && b == 0) break;
        // cout << power(a % 1000, b) % 1000 << endl;
        cout << power_2(a, b) % 1000 << endl;
    }
    return 0;
}
