#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int T, N;

int list[100001];
int main(){
    cin >> T;
    int count = 1;
    while(T--){
        cin >> N;
        list[0] = 0;
        // cin >> list[1];
        // int minus_min = 0, posi_max = 0;
        // if(list[0] > 0) posi_max = list[0];
        // if(list[0] < 0) minus_min = list[0];
        int maxI = 1, maxJ = 1, maxVal = INT8_MIN, tempJ = 1, tempI = 1, tempVal = INT8_MIN;
        for(int i = 1; i < N + 1; i++){
            cin >> list[i];
            if(list[i] < 0){
                if(list[i-1] < 0){
                    list[i] = list[i];
                    tempJ = i;
                    tempI = i;
                }else if(list[i-1] + list[i] < 0){
                    list[i] = list[i];
                    tempJ = i;
                    tempI = i;
                }else {
                    list[i] = list[i-1] + list[i];
                    tempI = i;
                }
            }else{
                if(list[i-1] < 0){
                    list[i] = list[i];
                    tempJ = i;
                    tempI = i;
                } 
                else{
                    list[i] = list[i-1] + list[i];
                    tempI = i;
                }
            }
            if(maxVal < list[i]){
                maxVal = list[i];
                maxI = tempI;
                maxJ = tempJ;
            }
        }
        for(int i = 1; i < N + 1; i++){

        }
        if(!T){
            cout << "Case " << count++ << ":" << endl;
            cout << maxVal << " " << maxJ << " " << maxI << endl;
        }else{
            cout << "Case " << count++ << ":" << endl;
            cout << maxVal << " " << maxJ << " " << maxI << endl << endl;
        }

    }
    return 0;
}