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
    string s,d;
    char c;

    while(cin >> c){
        if(find(s.begin(),s.end(),c) == s.end()){
            d += c;
        }
        s += c;
    }

    int len = s.length();
    int sum = 0;
    for(int i = 0;i<d.length();i++){
        int counter = count(s.begin(),s.end(),d[i]);
        sum += len - (counter-1);
    }

    cout << (len+1) * (26-d.length()) + sum;
}