#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10010
using namespace std;

int N;
int vis[MAX_INPUT];
struct step{
    int floor;
    int minStep;
};

int Vals[MAX_INPUT];

bool isEqual(int val, struct step t){
    return val == t.floor;
}

int main(){
    while(cin >> N && N){
        int start, end;
        cin >> start >> end;
        queue<struct step> q;
        for(int i = 1; i <= N; i++){
            cin >> Vals[i];
            vis[i] = 0;
        }
        struct step T;
        T.floor = start;
        T.minStep = 0;
        q.push(T);
        int flag = 1;
        while(!q.empty()){
            struct step val = q.front(); 
            q.pop();
            if(val.floor == end){
                cout << val.minStep << endl;
                flag = 0;
                break;  
            } 
            vis[val.floor] = 1;
            int up = val.floor + Vals[val.floor];
            int down = val.floor - Vals[val.floor];
            if(up <= N && !vis[up]){
                struct step T;
                T.floor = up;
                T.minStep = val.minStep + 1;
                q.push(T);
            }
            if(down >= 1 && !vis[down]){
                struct step T;
                T.floor = down;
                T.minStep = val.minStep + 1;
                q.push(T);
            }
        }
        if(flag) cout << -1 << endl;
    }
    return 0;
}