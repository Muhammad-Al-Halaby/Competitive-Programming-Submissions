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
   string s;
   cin >> s;
   char c;
   for(int i = 0;i<s.length();i++){
        cin >> c;
        if(c != s[i])cout << 1;
        else cout << 0;
   }
}