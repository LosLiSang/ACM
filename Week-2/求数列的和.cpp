#include<iostream>
#include<math.h>
// #include<iomanip>
using namespace std;

int main(){
    int start, n;
    while(cin >> start >> n){
        double res = 0, temp = start;
        while(n--){
            res += temp;
            temp = sqrt(temp);
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << res << endl;
    }
    return 0;
}