#include<iostream>
using namespace std;

int main(){
    int score;
    while(cin >> score){
        if (score > 100)
            cout << "Score is error!" << endl;
        else if (score >= 90)
            cout << "A" << endl;
        else if (score >= 80)
            cout << "B" << endl;
        else if (score >= 70)
            cout << "C" << endl;
        else if (score >= 60)
            cout << "D" << endl;
        else if (score >= 0)
            cout << "E" << endl;
        else
            cout << "Score is error!" << endl;
    }

    return 0;
}