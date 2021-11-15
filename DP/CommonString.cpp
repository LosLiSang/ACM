#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int list[1000][1000];

int main(){
    string str1;
    string str2;
    while(cin >> str1 >> str2){
        list[0][0] = 0;
        int totalMax = 0;
        for(int i = 0; i < str1.length(); i++){ // str1
            for(int j = 0; j < str2.length(); j++){ // str2
                int maxSize = 0, tempSize = 0;
                if(str1[i] == str2[j]) 
                    list[i+1][j+1] = list[i][j] + 1;
                else 
                    list[i+1][j+1] = max(list[i+1][j], list[i][j+1]);
                totalMax = max(list[i+1][j+1], totalMax);
            }
        }
        cout << totalMax << endl;
    }
    
    return 0;
}
