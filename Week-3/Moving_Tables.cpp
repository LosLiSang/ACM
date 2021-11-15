#include<iostream>
#include<math.h>
#include<algorithm>
#include<malloc.h>
using namespace std;

int N;

int main(){
    cin >> N;
    int corridor[200];
    while(N--){
        int n;
        fill(corridor, corridor+200, 0);
        cin >> n;
        int start, end;
        for(int i = 0; i < n; i++){
            cin >> start >> end;
            start = (start-1) /2;
            end = (end-1) / 2;
            if(start > end)
                while(start >= end){
                    corridor[end]++;
                    end++;
                }
            else
                while(start <= end){
                    corridor[start]++;
                    start++;
                }
        }
        int max = 0;
        for(int i = 0; i < 200; i++){
            if(max < corridor[i])
                max = corridor[i];
        }
        cout << max * 10 << endl;
    }
    return 0;
}