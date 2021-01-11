#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int main(){
    vector<char> name;
    char x;
    while(cin >> x)
        if(find(name.begin(),name.end(),x) == name.end()) name.push_back(x);
    if(name.size() % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}