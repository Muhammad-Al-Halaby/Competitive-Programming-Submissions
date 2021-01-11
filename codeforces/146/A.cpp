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
    int n;
    cin >> n;
    string s;
    char c;
    bool lucky = true;
    while(cin >> c){
        if(c != '7' && c != '4') lucky = false;
        s += c;
    }

    if(lucky){
        int r = 0;
        int l = 0;
        for(int i = 0;i<n/2;i++){
            r += s[i]-'0';
            l += s[i+n/2]-'0';
        }
        if(r == l)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
}