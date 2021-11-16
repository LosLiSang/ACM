#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 12
using namespace std;

class Point{
    public:
        // char char_x;
        int x;
        int y;
        int step;
        Point(int x, int y, int step): x(x), y(y), step(step) {};
        void show(){
            cout << x << " " << y << " " << step << endl;
            return;
        }
};

struct{
    int x;
    int y;
}list[8];

int vis[MAX_INPUT][MAX_INPUT];

Point changePoint(Point p, int x, int y){
    return Point(p.x + x, p.y + y, p.step + 1);
}

int main(){
    string start, end;
    list[0].x = 1;
    list[0].y = 2;
    list[1].x = -1;
    list[1].y = 2;
    list[2].x = 1;
    list[2].y = -2;
    list[3].x = -1;
    list[3].y = -2;
    list[4].x = 2;
    list[4].y = 1;
    list[5].x = -2;
    list[5].y = 1;
    list[6].x = 2;
    list[6].y = -1;
    list[7].x = -2;
    list[7].y = -1;
    while(cin >> start >> end){
        Point src = Point(int(start[0] - 'a'), int(start[1] - '1'), 0);
        Point dest = Point(int(end[0] - 'a') , int(end[1] - '1'), 0);
        queue<Point> q;
        q.push(src);
        int flag = 1;
        memset(vis, 0, sizeof(vis));
        vis[src.x][src.y] = 1;
        while(!q.empty()){
            Point val = q.front();
            // val.show();
            if(val.x == dest.x && val.y == dest.y){
                printf("To get from %s to %s takes %d knight moves.\n", start.c_str(), end.c_str(), val.step);
                // cout << val.step << endl;
                flag = 0;
                break;
            }
            q.pop();
            vis[val.x][val.y] = 1;
            for(int i = 0; i < 8; i++){
                Point T = Point(0, 0, 0);
                T = changePoint(val, list[i].x, list[i].y);
                if(!vis[T.x][T.y] && T.x >= 0 && T.y >= 0 && T.x < 8 && T.y < 8){
                    q.push(T);
                    vis[T.x][T.y] = 1;
                }
            }
        }
        // if(flag)
        //     cout << "NO" << endl;
    }
    return 0;
}