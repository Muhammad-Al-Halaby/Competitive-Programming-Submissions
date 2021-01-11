#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<iomanip>
#include<utility>
#include<numeric>
#include<set>

using namespace std;

int main(){
    string s,t;
    cin >> s;
    int counter = 1;
    char c;
    while(cin >> c){
        if(s[0] == c){
            s.replace(0,1,"");
            counter++;
        }
    }
    cout << counter;
}