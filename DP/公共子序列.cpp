#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int list[1000][1000];
// 超时Code
int main(){
    string str1;
    string str2;
    while(cin >> str1 >> str2){
        list[0][0] = 0;
        int totalMax = 0;
        for(int i = 0; i < str1.length(); i++){ // str1
            for(int j = 0; j < str2.length(); j++){ // str2
                int maxSize = 0, tempSize = 0;
                for(int k = 0; k <= j; k++){
                    if(str1[i] == str2[k]){
                        tempSize = list[i][k] + 1;
                    }
                }
                maxSize = max(maxSize, tempSize);
                for(int k = 0; k <= i; k++){
                    if(str1[k] == str2[j]){
                        tempSize = list[k][j] + 1;
                    }
                }
                maxSize = max(maxSize, tempSize);
                list[i+1][j+1] = maxSize;
                totalMax = max(list[i+1][j+1], totalMax);
            }
        }
        cout << totalMax << endl;
    }
    
    return 0;
}
