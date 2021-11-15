#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
long long list[32];


int main(){
    cin >> n;
    list[1] = 1;
    list[2] = 3;
    for(int i = 3; i < 32; i++){
        list[i] = list[i-1] + 2*list[i-2];
    }
    while(n--){
        int temp;
        cin >> temp;
        cout << list[temp] << endl;
    }
    return 0;
}