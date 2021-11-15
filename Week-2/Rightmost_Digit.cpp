#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        int right = num % 10;
        int res;
        if(num == 0) cout << 1 << endl;
        else
        switch (right)
        {
        case 0:
            cout << 0 << endl;
            break;
        case 1:
            cout << 1 << endl;
            break;
        case 2:
            if(num % 4 == 0) cout << 6 << endl;
            if(num % 4 == 1) cout << 2 << endl;
            if(num % 4 == 2) cout << 4 << endl;
            if(num % 4 == 3) cout << 8 << endl;
            break;
        case 3:
            if(num % 4 == 0) cout << 1 << endl;
            if(num % 4 == 1) cout << 3 << endl;
            if(num % 4 == 2) cout << 9 << endl;
            if(num % 4 == 3) cout << 7 << endl;
            break;
        case 4:
            if(num % 2 == 0) cout << 6 << endl;            
            if(num % 2 == 1) cout << 4 << endl;
            break;
        case 5:
            cout << 5 << endl;
            break;
        case 6:
            cout << 6 << endl;
            break;
        case 7:
            if(num % 4 == 0) cout << 1 << endl;
            if(num % 4 == 1) cout << 7 << endl;
            if(num % 4 == 2) cout << 9 << endl;
            if(num % 4 == 3) cout << 3 << endl;
            break;
        case 8:
            if(num % 4 == 0) cout << 6 << endl;
            if(num % 4 == 1) cout << 8 << endl;
            if(num % 4 == 2) cout << 4 << endl;
            if(num % 4 == 3) cout << 2 << endl;
            break;
        case 9:
            if(num % 2 == 0) cout << 1 << endl;
            if(num % 2 == 1) cout << 9 << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
