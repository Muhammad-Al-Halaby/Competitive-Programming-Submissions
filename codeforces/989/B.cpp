#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool changed[3000];
int main(){

    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    for(int i = 0;i<n-p;i++){
        if(s[i] == '.' && s[i+p] == '.'){
                s[i] = '1';s[i+p]='0';
        }
        else if(s[i] == '.' && s[i+p] != '.')
            s[i] = !(s[i+p]-'0')+'0';
        else if(s[i] != '.' && s[i+p] == '.')
            s[i+p] = !(s[i]-'0')+'0';
        else if(s[i] != '.' && s[i+p] != '.');
    }
    int cnt=0;
    for(int i = 0;i<n-p;i++){
        if(s[i] == s[i+p])cnt++;
    }
    if(cnt == n-p)cout << "NO";
    else{
            for(int i = 0;i<s.length();i++){
                if(s[i] == '.')s[i] = '0';
            }
            cout << s;
    }
}