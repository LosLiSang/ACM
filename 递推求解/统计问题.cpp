#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;

long long up[21];
long long lf[21];
long long rh[21];
long long sum[21];

int main(){
    cin >> n;
    sum[1] = 3;
    sum[2] = 7;
    up[1] = 1;
    up[2] = 3;
    lf[1] = 1;
    lf[2] = 2;
    rh[1] = 1;
    rh[2] = 2;
    for(int i = 3; i < 21; i++){
        lf[i] = lf[i-1] + up[i-1];
        rh[i] = rh[i-1] + up[i-1];
        up[i] = sum[i-1];
        sum[i] = up[i] + lf[i] + rh[i];
    }
    while(n--){
        int temp;
        cin >> temp;
        cout << sum[temp] << endl;
    }
    return 0;
}