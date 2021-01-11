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
    string s;
    cin >> n >> s;
    int counter = 0;
    for(int i = 0;i < n;i++){
        if(i+1 != n && s[i] == s[i+1])counter++;
    }
    cout << counter;
}