#include<stdio.h>

int main(){
    int count;
    while(scanf("%d", &count) == 1){
        int res = 0;
        for(int i = 0; i < count; i++){
            int temp;
            scanf("%d", &temp);
            res += temp;
        }
        printf("%d\n", res);
    }
    return 0;
}