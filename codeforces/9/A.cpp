#include <iostream>

using namespace std;

int main(){
    int Y,W;
    cin >> Y >> W;
    int prob = 7-max(Y,W);
    if(prob == 0) cout << "0/1";
    else if(prob == 1) cout << "1/6";
    else if(prob == 2) cout << "1/3";
    else if(prob == 3) cout << "1/2";
    else if(prob == 4) cout << "2/3";
    else if(prob == 5) cout << "5/6";
    else if(prob == 6) cout << "1/1";
}