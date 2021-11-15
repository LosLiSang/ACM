#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 1001
using namespace std;

int Size, NSize, MSize;

class State{
    public:
        int handelCount;
        int Size;
        int NSize;
        int MSize;
        State(int handelCount, int Size, int MSize, int NSize): handelCount(handelCount), Size(Size), MSize(MSize), NSize(NSize){}
};


int vis[MAX_INPUT][MAX_INPUT];

State changeState(int src_btn, int dest_btn, int dest_size){
    // cout << src_btn << " " << dest_btn << endl;
    if(src_btn + dest_btn >= dest_size){
        src_btn = src_btn + dest_btn - dest_size;
        dest_btn = dest_size;
    }else{
        dest_btn = src_btn + dest_btn;
        src_btn = 0;
    }
    // cout << src_btn << " " << dest_btn << endl;
    return State(0, src_btn, dest_btn, Size - src_btn - dest_btn);
}


int main(){
    while(cin >> Size >> MSize >> NSize && (Size || NSize || MSize)){
        memset(vis, 0, sizeof(vis));
        queue<State> q;
        q.push(State(0, Size, 0, 0));
        if(Size % 2 == 1){
            cout << "NO" << endl;
            continue;
        }
        vis[Size][0] = 1;
        int flag = 1;
        while(!q.empty()){

            State val = q.front();
            // cout << val.handelCount << " " << val.Size << " " << val.MSize << " " << val.NSize << endl;
            
            if(val.MSize == val.Size && val.Size == Size / 2 || val.NSize == val.MSize && val.NSize == Size / 2 || val.Size == val.NSize && val.Size == Size / 2){
                cout << val.handelCount << endl;
                flag = 0;
                break;
            }
            q.pop();
            
            // int size1 = val.Size, size2 = val.MSize, size3 = val.NSize;
            State T = State(1,2,3,4);
            
            T = changeState(val.MSize, val.Size, Size);
            if(!vis[T.MSize][T.Size]){
                q.push(State(val.handelCount + 1, T.MSize, T.Size, T.NSize));
                vis[T.MSize][T.Size] = 1;
            }
            
            T = changeState(val.Size, val.MSize, MSize);
            if(!vis[T.Size][T.MSize]){
                q.push(State(val.handelCount + 1, T.Size, T.MSize, T.NSize));
                vis[T.Size][T.MSize] = 1;
            }
            
            T = changeState(val.MSize, val.NSize, NSize);
            if(!vis[T.NSize][T.Size]) {
                q.push(State(val.handelCount + 1, T.NSize, T.Size, T.MSize)); 
                vis[T.NSize][T.Size] = 1;    
            }

            T = changeState(val.NSize, val.MSize, MSize);
            if(!vis[T.NSize][T.MSize]){
                q.push(State(val.handelCount + 1, T.NSize, T.MSize, T.Size));
                vis[T.NSize][T.MSize] = 1;
            }
            
            T = changeState(val.NSize, val.Size, Size);
            if(!vis[T.MSize][T.NSize]){
                q.push(State(val.handelCount + 1, T.MSize, T.NSize, T.Size));
                vis[T.MSize][T.NSize] = 1;
            }
            
            T = changeState(val.Size, val.NSize, NSize);
            if(!vis[T.Size][T.NSize]){
                q.push(State(val.handelCount + 1, T.Size, T.NSize, T.MSize));
                vis[T.Size][T.NSize] = 1;
            }  
                
        }
        if(flag) cout << "NO" << endl;
    }
    return 0;
}