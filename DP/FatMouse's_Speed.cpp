#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct data{
    int w;
    int speed;
    int id;
}list[1002];

int res[1002][1002];

bool cmp(struct data d1, struct data d2){
    if(d1.w == d2.w) return d1.speed < d2.speed;
    return d1.w < d2.w;
}

int main(){
    int n = 1;
    while(cin >> list[n].w >> list[n].speed){
        list[n].id = n;
        n++;
    }
    // cout << n << endl;
    sort(list + 1, list + n, cmp);
    res[0][0] = 0;
    res[1][0] = 1;
    res[1][1] = list[1].id;
    int total_max_size = 0, total_max_index = 0;
    for(int i = 2; i < n; i++){
        int tempSize = 0, maxSize = 0, tempIndex = 0, maxIndex = 0;
        for(int j = 1; j < i; j++){
            if(list[i].w != list[j].w && list[i].speed < list[j].speed){
                tempSize = res[j][0] + 1;
                tempIndex = j;
            } else{
                tempSize = 1;
                tempIndex = 0;
            } 
            if(tempSize > maxSize){
                maxSize = tempSize;
                maxIndex = tempIndex;
            }
        }
        res[i][0] = maxSize;
        for(int j = 1; j < maxSize; j++){
            res[i][j] = res[maxIndex][j];
        }
        res[i][maxSize] = list[i].id;
        if(total_max_size < res[i][0]){
            total_max_index = i;
            total_max_size = res[i][0];
        }
    }
    // printf("?\n");
    // cout << total_max_index << " " <<  total_max_size << endl;
    cout << res[total_max_index][0] << endl;
    for(int i = 1; i < total_max_size + 1; i++){
        cout << res[total_max_index][i] << endl;
    }
    return 0;
}