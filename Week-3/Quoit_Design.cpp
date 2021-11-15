#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n;

struct point{
    double x;
    double y;
};

bool cmp(struct point p1, struct point p2){
    return p1.x + p1.y < p2.x + p2.y;
}

double distance(struct point p1, struct point p2){
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

int main(){
    struct point points[100005];
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;
        sort(points, points + n, cmp);
        double min = INT16_MAX;
        for(int i = 1; i < n; i++){
            double temp = distance(points[i-1], points[i]);
            if(min > temp) min = temp;
        }
        printf("%.2lf\n", min/2);
    }
    return 0;
}