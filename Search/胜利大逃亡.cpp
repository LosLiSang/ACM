#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 60
using namespace std;

int N;

int vis[MAX_INPUT][MAX_INPUT][MAX_INPUT];
int war[MAX_INPUT][MAX_INPUT][MAX_INPUT];
// int step[MAX_INPUT][MAX_INPUT][MAX_INPUT];
int move_step[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

class State{
    public:
        int x;
        int y;
        int z;
        int step;
        State(int x, int y, int z, int step): x(x), y(y), z(z), step(step) {};
        void show(){
            cout << x << " " << y << " " << z << " " << step << endl;
            return;
        }
};

State changeMove(State s, int x, int y, int z){
    return State(s.x + x, s.y + y, s.z + z, s.step + 1);
}

int main(){
    cin >> N;
    int a, b, c, time;
    while(N--){
        cin >> a >> b >> c >> time;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                for(int k = 0; k < c; k++){
                    scanf("%d", &(war[i][j][k]));
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        queue<State> q;
        q.push(State(0, 0, 0, 0));
        vis[0][0][0] = 1;
        int flag = 1;
        while(!q.empty()){
            State val = q.front();
            q.pop();
            // val.show();
            if(val.step > time) break;
            if(val.x == a-1 && val.y == b-1 && val.z == c-1){
                cout << val.step << endl;
                flag = 0;
                break;
            }
            for(int i = 0; i < 6; i++){
                State T = changeMove(val, move_step[i][0], move_step[i][1], move_step[i][2]);
                if(T.x < 0 || T.y < 0 || T.z < 0 || T.x >= a || T.y >= b || T.z >= c || war[T.x][T.y][T.z] == 1){
                    continue;
                }
                if(!vis[T.x][T.y][T.z]){
                    vis[T.x][T.y][T.z] = 1;
                    q.push(T);
                }
            }
        }
        if(flag) cout << -1 << endl;
    }
    return 0;
}