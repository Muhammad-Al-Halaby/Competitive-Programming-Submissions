#include <iostream>
#include <string>

using namespace std;

int main(){
    string x;
    cin >> x;
    while(x.length() != 0){
        if(x[0] == '-' && x[1] == '.'){
            x.replace(0,2,"");
            cout << 1;
        }
        else if(x[0] == '-' && x[1] == '-'){
            x.replace(0,2,"");
            cout << 2;
        }
        else{
            x.replace(0,1,"");
            cout << 0;
        }
    }
}