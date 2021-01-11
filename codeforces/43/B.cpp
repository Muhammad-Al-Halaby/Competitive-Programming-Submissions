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
    string s1,s2;
    getline(cin,s1);
    int counter = 0;
    char c;
    while(cin >> c){
        int f = s1.find(c);
        if(c != ' ' && f != -1){
            s1.replace(f,1,"");
            counter++;
        }
        if(c != ' ') s2 += c;
    }

    if(counter == s2.length())cout << "YES";
    else cout << "NO";
}