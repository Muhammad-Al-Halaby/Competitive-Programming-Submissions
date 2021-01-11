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
    char c,s;
    while(cin >> c){
        if(isalpha(c))s=tolower(c);
    }
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y')cout << "YES";
    else cout << "NO";
}