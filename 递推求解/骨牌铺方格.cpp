#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

long long list[51];



int main(){
    int n;
    list[1] = 1;
    list[2] = 2;
    list[3] = 3; 
    for(int i = 4; i < 51; i++){
        list[i] = list[i-1] + list[i-2];
    }
    while(cin >> n){
        cout << list[n] << endl;
    }

    return 0;
}