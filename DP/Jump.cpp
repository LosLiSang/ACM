#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
int list[1002];
long long res[1002];


int main(){
    while(cin >> n && n){
        for(int i = 0; i < n; i++){
            cin >> list[i];
        }
        res[0] = list[0];
        int resMax = 0;
        for(int i = 1; i < n; i++){
            int max = list[i];
            for(int j = 0; j < i; j++){
                if(list[i] > list[j]){
                    max = max > list[i] + res[j] ? max : list[i] + res[j];
                }
            }
            res[i] = max;
            resMax = resMax > max ? resMax : max;
        }
        cout << resMax <<endl;
    }
    return 0;
}