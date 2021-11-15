#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
long long list[10001];

int main(){
    cin >> n;
    list[1] = 2;
    list[2] = 7;
    for(int i = 3; i < 10001; i++){
        list[i] = list[i-1] + 4 * i - 3;
    }
    while(n--){
        int temp;
        cin >> temp;
        cout << list[temp] << endl;
    }
    return 0;
}