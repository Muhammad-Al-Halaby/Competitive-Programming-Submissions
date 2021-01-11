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
   int zeros = 0,ones = 0;
   for(int i = 0;i<s.length();i++){
       if(zeros == 7 || ones == 7)break;
       if(s[i] == '0'){ones=0;zeros++;}
       else if(s[i] == '1'){zeros=0;ones++;}
   }
    (zeros == 7 || ones == 7) ? cout << "YES" : cout << "NO";
}