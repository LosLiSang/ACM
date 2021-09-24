#include<stdio.h>

int main(){
    int count = 0;
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        int n = 0;
        scanf("%d", &n);
        int sum = 0;
        for(int j = 0; j < n; j++){
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d\n\n", sum);
    }
    return 0;
}