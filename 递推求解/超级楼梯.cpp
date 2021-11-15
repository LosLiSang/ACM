#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
long long list[41];

int main(){
    cin >> n;
    list[1] = 1, list[2] = 1;
    for(int i = 2; i < 41; i++){
        list[i] = list[i-1] + list[i-2];
    }
    while(n--){
        int temp;
        cin >> temp;
        cout << list[temp] << endl;
    }
    return 0;
}