#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
 long long res[101] = {0};


int main(){
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i < 101; i++){
        int temp = 0;
        for(int j = 0; j < i; j++){
            temp += res[j] * res[i-j-1];
            // cout << temp << " "; // 0 2
            // 1 1
            // 2 0 
        }
        // cout << endl;
        res[i] = temp;
    }

    while(cin >> n && n != -1){
        cout << res[n] << endl;
    }

    return 0;
}