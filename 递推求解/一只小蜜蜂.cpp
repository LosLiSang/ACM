#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int N;

long long list[51];

int main(){
    cin >> N;
    
    list[1] = 1;
    list[2] = 2;
    for(int i = 3; i < 51; i++){
        list[i] = list[i-1] + list[i-2];
    }

    while(N--){
        int a, b;
        cin >> a >> b;
        cout << list[b-a] << endl;
    }
    return 0;
}
