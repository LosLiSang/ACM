#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;


int n;
int list[5843];

int min_4(int a, int b, int c, int d){
    int min = a;
    min = min < b ? min : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    return min;
}

int main(){
    list[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
    for(int i = 2; i < 5843; i++){
        list[i] = min_4(list[p2] * 2, list[p3] * 3, list[p5] * 5, list[p7] * 7);
        if(list[i] % 2 == 0) p2++;
        if(list[i] % 3 == 0) p3++;
        if(list[i] % 5 == 0) p5++;
        if(list[i] % 7 == 0) p7++;
        // cout << p2 << " " << p3 << " " << p5 << " " << p7 << endl;
    }
    while(cin >> n && n){
        
        if(n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
            printf("The %dth humble number is %d.\n", n, list[n]);
        else if(n % 10 == 1)
            printf("The %dst humble number is %d.\n", n, list[n]);
        else if(n % 10 == 2)
            printf("The %dnd humble number is %d.\n", n, list[n]);
        else if(n % 10 == 3)
            printf("The %drd humble number is %d.\n", n, list[n]);
        else
            printf("The %dth humble number is %d.\n", n, list[n]);

    }
    return 0;
}