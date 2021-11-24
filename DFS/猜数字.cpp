#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10010
using namespace std;

int N;
int guess_list[4];
int dest_list[4];

int dest[MAX_INPUT];
int p[MAX_INPUT];
int t[MAX_INPUT];

void dispose_guess(int guess){
    guess_list[0] = guess / 1000 % 10;
    guess_list[1] = guess / 100 % 10;
    guess_list[2] = guess / 10 % 10;
    guess_list[3] = guess % 10;
}

void dispose_dest(int dest){
    dest_list[0] = dest / 1000 % 10;
    dest_list[1] = dest / 100 % 10;
    dest_list[2] = dest / 10 % 10;
    dest_list[3] = dest % 10;
}

int position(){
    int count_ = 0;
    for(int i = 0; i < 4; i++){
        if(dest_list[i] == guess_list[i]) count_++; 
    }
    return count_;
}

int same(){
    int flag[4];
    memset(flag, 0, sizeof(flag));
    int count_ = 0;
    for(int i = 0; i < 4; i++){
        // cout << flag[0] <<flag[1] << flag[2] << flag[3] <<endl;
        for(int j = 0; j < 4; j++){
            if(!flag[j]){
                if(dest_list[j] == guess_list[i]){
                    flag[j] = 1;
                    count_++;
                    break;
                }
            }
        }
    }
    return count_;
}

int main(){
    while(cin >> N && N){
        for(int i = 0; i < N; i++){
            cin >> dest[i] >> t[i] >> p[i];
        }
        int one = 0;
        int res = 0;
        for(int i = 1000; i <= 9999; i++){
            dispose_guess(i);
            int flag = 0;
            for(int j = 0; j < N; j++){
                dispose_dest(dest[j]);
                if(same() != t[j] || position() != p[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                one += 1;
                if(one > 1) break;
                res = i;
            }
        }
        if(one == 1)
            cout << res << endl;
        else{
            cout << "Not sure" << endl;
        }
    }
    return 0;
}