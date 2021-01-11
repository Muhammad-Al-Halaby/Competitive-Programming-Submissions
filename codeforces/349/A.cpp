#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int bills[n],temp;
    for(int i = 0;i<n;i++){
            cin >> temp;
            bills[i] = temp;
    }
    int b_25=0,b_50=0;
    bool can = true;
    for(int i = 0;i<n;i++){
        if(bills[i] == 25){
            b_25++;
        }
        else if(bills[i] == 50){
            if(b_25 >= 1){
                    b_25--;
                    b_50++;
            }
            else{
                can = false;
                break;
            }
        }
        else if(bills[i] == 100){
            if(b_25 - 1 >= 0 && b_50 - 1 >= 0){
                    b_25-=1;
                    b_50--;
            }
            else if(b_25 - 3 >= 0){
                b_25 -=3;
            }
            else{
                can = false;
                break;
            }
        }
    }
    if(can == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}