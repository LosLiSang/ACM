#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10010
using namespace std;

int Size, NSize, MSize;

class State{
    public:
        int handelCount;
        int Size;
        int NSize;
        int MSize;
        State(int handelCount, int Size, int NSize, int MSize): handelCount(handelCount), Size(Size), NSize(NSize), MSize(MSize){}
};


int vis[MAX_INPUT][MAX_INPUT];

int main(){
    while(cin >> Size >> NSize >> MSize && (Size || NSize || MSize)){
        memset(vis, 0, sizeof(vis));
        queue<State> q;
        q.push(State(0, Size, 0, 0));
        int flag = 1;
        while(!q.empty()){

            State val = q.front();
            if(val.MSize + val.NSize == val.Size || val.Size + val.NSize == val.MSize || val.Size + val.MSize == val.NSize){
                cout << val.handelCount << endl;
                flag = 0;
                break;
            }
            q.pop();
            vis[val.Size][val.MSize] = 1;
            // int size1 = val.Size, size2 = val.MSize, size3 = val.NSize;
            if(val.Size + val.MSize >= MSize){
                int size1 = val.Size, size2 = val.MSize, size3 = val.NSize;
                size1 = size1 + size2 - MSize;
                size2 = MSize;
                if(!vis[size1][size2]) 
                    q.push(State(val.handelCount + 1, size1, size2, size3));
            }else{
                int size1 = val.Size, size2 = val.MSize, size3 = val.NSize;
                size2 = size1 + size2;
                size1 = 0;
                if(!vis[size1][size2]) 
                    q.push(State(val.handelCount + 1, size1, size2, size3));
            }

                
        }
    }
    return 0;
}