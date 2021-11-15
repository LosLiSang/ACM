#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if (n == 0) break;
        int total_time = n * 5, level, last_level = 0;
        for(int i = 0; i < n; i++){
            cin >> level;
            if (level > last_level)
                total_time += 6 * (level - last_level);
            else 
                total_time += 4 * (last_level - level);
            last_level = level;
        }
        cout << total_time << endl;
    }
    return 0;
}