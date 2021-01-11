#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int price,quality;
    bool exist;
    for(int i =0;i<n;i++){
        cin >> price >>  quality;
        if(quality > price){
            exist = true;
            break;
        }
        else{
            exist = false;
        }
    }
    if(exist){
        cout << "Happy Alex" << endl;
    }
    else{
        cout << "Poor Alex" << endl;
    }
}