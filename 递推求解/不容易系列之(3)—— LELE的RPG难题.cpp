#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

long long list[51];

int main(){
    int n;
    list[0] = 0;
    list[1] = 3;
    list[2] = 6;
    list[3] = 6;
    for(int i = 4; i < 51; i++){
        list[i] = list[i-1] + 2 * list[i-2];
    }
    while(cin >> n){
        cout << list[n] << endl;
    }

    return 0;
}