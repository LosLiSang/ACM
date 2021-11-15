#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int list[] = {1, 2 ,3, 2, 2, 1, 3, 1};
    int n;
    while(cin >> n){
        if(list[n % (sizeof(list) / sizeof(int))] == 3)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}