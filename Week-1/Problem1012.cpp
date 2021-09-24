#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int res = 1;
        for(int i = 0; i < n; i++){
            int temp = 1;
            cin >> temp;
            if(temp % 2 == 1)
                res *= temp;
        }
        cout << res << endl;
    }
    return 0;
}