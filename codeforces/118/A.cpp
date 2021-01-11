#include <iostream>
#include <string>

using namespace std;

int main(){
    string x;
    cin >> x;
    for(int i = 0;i< x.length();i++){
        x[i] = tolower(x[i]);
        if(x[i] == 'a' || x[i] == 'e' || x[i] == 'o' || x[i] == 'u' || x[i] == 'y' || x[i] == 'i'){
            x.replace(i,1,"");
            i--;
        }
        else{
            if(x[i] != '.' && x[i-1] != '.'){
            x.insert(i,".");
            i--;
            }
        }
    }

    cout << x << endl;
}