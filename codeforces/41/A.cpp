#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    reverse(s.begin(),s.end());
    if(s == t){
        cout << "YES" <<endl;
    }
    else {
        cout << "NO" <<endl;
    }
}