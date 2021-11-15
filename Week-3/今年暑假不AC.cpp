#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct show{
    int start;
    int end;
};


bool cmp(struct show a, struct show b){
    if(a.end == b.end) return a.start < b.start;
    else return a.end < b.end;
}

int n;
int main(){
    struct show list[100];
    while(cin >> n){
        if(n == 0) break;
        
        for(int i = 0; i < n; i++)
            cin >> list[i].start >> list[i].end;
        sort(list, list+n, cmp);
        // cout << "a";
        int count = 0, itr = 0, end = list[0].end;
        while(itr < n){
            int i;
            for(i = itr; end > list[i].start; i++);
            itr = i;
            end = list[itr].end;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}