#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    cin >> c;
    string s="qwertyuiopasdfghjkl;zxcvbnm,./";
    string s1;
    cin >> s1;
    for(int i = 0;i<s1.length();i++){
        for(int j = 0;j<s.length();j++){
            if(c=='R' && s[j]==s1[i]){cout << s[j-1];break;}
            else if(c =='L' && s[j]==s1[i]){cout << s[j+1];}
        }
    }
}