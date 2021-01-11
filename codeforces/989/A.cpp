#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int y = 0;
    string arr[] = {"ABC","ACB","BAC","BCA","CAB","CBA"};
    for(int i = 0;i<6;i++){
        if(strstr(s.c_str(),arr[i].c_str())){
            cout << "Yes";
            y = 1;
            break;
        }
    }
    if(!y)cout << "No";
}