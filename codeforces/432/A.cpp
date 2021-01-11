#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int temp=0;
    int members=0;
    for(int i =0;i<n;i++){
        cin >> temp;
        if(temp + k <= 5){
            members++;
        }
    }
    int teams = members / 3;
    cout << teams;


}