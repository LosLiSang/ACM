#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int T, N;

int list[100001];
// 超时Code
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        list[0] = 0;
        cin >> list[1];
        // int minus_min = 0, posi_max = 0;
        // if(list[0] > 0) posi_max = list[0];
        // if(list[0] < 0) minus_min = list[0];
        for(int i = 2; i < N + 1; i++){
            cin >> list[i];
            list[i] = list[i] + list[i-1];
        }
        int maxI, maxJ, maxVal = INT8_MIN;
        for(int i = 1; i < N + 1; i++){
            for(int j = 0; j <= i; j++){
                if(maxVal < list[i] - list[j]){
                    maxVal = list[i] - list[j];
                    maxI = i; 
                    maxJ = j;
                }
            }
        }
        cout << "Case " << N << ":" << endl;
        cout << maxVal << " " << maxJ + 1 << " " << maxI <<  endl << endl;
    }
    return 0;
}