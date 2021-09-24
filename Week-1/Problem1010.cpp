#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double res = sqrt(pow(x2 - x1 ,2) + pow(y2 - y1, 2));
    
    cout.precision(2);
    cout.setf(ios::fixed); 
    cout << res;
    return 0;
}