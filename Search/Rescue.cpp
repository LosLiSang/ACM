#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 210
using namespace std;





int vis[MAX_INPUT][MAX_INPUT];
int N, M;
int war[MAX_INPUT][MAX_INPUT];
// int time[MAX_INPUT][MAX_INPUT];
int move_size[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


class Point{
    public:
        int x;
        int y;
        int step;
        Point(int x, int y, int step): x(x), y(y), step(step) {};
        bool operator<(const Point& p1) const {
            return step > p1.step;
        }
        void show(){
            cout << x << " " << y << " " << step << " " << char(war[x][y]) << endl;
            return;
        };
        // Point(int c) step(c) {};
};

Point movePoint(Point p, int x, int y){
    return Point(p.x + x, p.y + y, p.step + 1);
}

int main(){
    while(cin >> N >> M){
        int start_x, start_y;
        for(int i = 0; i < N; i++){
            string line;
            cin >> line;
            for(int j = 0; j < M; j++){
                war[i][j] = line[j];
                if(line[j] == 'a'){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        priority_queue<Point> q;
        q.push(Point(start_x, start_y, 0));
        vis[start_x][start_y] = 1;
        int flag = 1;
        while(!q.empty()){
            Point val = q.top();
            q.pop();
            // 输出
            // val.show();
            if(war[val.x][val.y] == int('r')){
                cout << val.step << endl;
                flag = 0;
                break;
            }
            for(int i = 0; i < 4; i++){
                Point T = movePoint(val, move_size[i][0], move_size[i][1]);
                if(war[T.x][T.y] == '#') continue;
                if((war[T.x][T.y] == '.' || war[T.x][T.y] == 'r') && !vis[T.x][T.y]){
                    q.push(T);
                    vis[T.x][T.y] = 1;
                }
                if(war[T.x][T.y] == 'x' && !vis[T.x][T.y]){
                    T.step += 1;
                    q.push(T);
                    vis[T.x][T.y] = 1;
                }
            }
        }
        if(flag)
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
    return 0;
}