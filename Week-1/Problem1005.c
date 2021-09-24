#include<stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int num_count = 0;
        scanf("%d", &num_count);
        int sum = 0;
        for(int j = 0; j < num_count; j++){
            int temp = 0;
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d", sum);
    }
    return 0;
}