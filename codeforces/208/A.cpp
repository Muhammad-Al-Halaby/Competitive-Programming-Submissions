#include<bits/stdc++.h>
using namespace std; 

int main(){
    string s;
    int last=-1;
    cin >> s;
    bool con;
    for(int i = 0;i<s.length();i++){
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            i+=2;
        }
        else{
            if(last != -1 && i != last+1)cout << ' ';
            last = i;
            cout << s[i];
        }
    }
}