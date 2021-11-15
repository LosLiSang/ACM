#include<iostream>
using namespace std;


int main(){
    int num1, num2;
    while(cin >> num1 >> num2){
        int temp, a = num1, b = num2;
        do{
            temp = a % b;
            a = b;
            b = temp;
        }while(temp != 0);
        cout << num1 * num2 / a << endl;
    }
    return 0;
}