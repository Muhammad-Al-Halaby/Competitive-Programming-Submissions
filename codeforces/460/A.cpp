#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int days = n;
    for(int i = 1;i<=100;i++){
        if(m*i <= n){
            n++;
            days++;
        }
    }
    cout << days;
}