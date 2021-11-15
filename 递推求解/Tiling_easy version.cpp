#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int N;

long long list[31];

int main(){
    cin >> N;
    list[1] = 1;
    list[2] = 3;
    for(int i = 3; i < 31; i++){
        list[i] = list[i-1] + list[i-2] * 4;
    }

    while(N--){
        int temp;
        cin >> temp;
        cout << list[temp] << endl;
    }
    return 0;
}