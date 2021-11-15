#include<iostream>
using namespace std;

int main(){
    int count;
    cin >> count;
    while(count-- > 0){
        int n, res = 1;
        cin >> n;
        int num;
        for(int i = 0; i < n; i++){
            int num1, num2, temp;
            cin >> num;
            num1 = num;
            num2 = res;
            // if (num > res){
            //     num1 = num;
            //     num2 = res;
            // } else {
            //     num1 = res;
            //     num2 = num;
            // }
            while(num1 % num2 != 0){
                temp = num1 % num2;
                num1 = num2;
                num2 = temp;
            }
            res = res / num2 * num ;
        }
        cout << res << endl;
    }
    return 0;
}