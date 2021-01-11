#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n >= 1 && n <= 100){
        double temp;
        double sum=0;
        for(int i = 0;i < n;i++){
            cin >> temp;
            sum +=temp;
        }
        double cocktail = sum /n;
        cout << cocktail << endl;
    }
}