#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string line;
    int plus = 0;
    int minus = 0;
    for(int i = 0;i<n;i++){
        cin >> line;
        for(int j =0;j<line.length();j++){
            if(line[j] == '+') plus++;
            else if(line[j] == '-') minus++;
        }
    }
    
    plus = plus/2;
    minus = minus/2;
    cout << plus - minus;
}