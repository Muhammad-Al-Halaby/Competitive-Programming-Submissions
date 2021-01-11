#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin >> s;
    int x=0;
    
    for(int i = 0;i < s.length();i++){
        if(i+2 <= s.length() - 1){
         if(s[i] == '1' && s[i+1] == '4' && s[i+2] == '4'){
            s[i]='x';s[i+1]='x';s[i+2]='x';
            i+=2;
            x+=3;
         }
        }
    }
    for(int i = 0;i < s.length();i++){
      if(i+1 <= s.length() - 1){
          if(s[i] == '1' && s[i+1] == '4'){
              s[i]='x';s[i+1]='x';
              i+=1;
              x+=2;
          }
      }
    }
    for(int i = 0;i<s.length();i++)if(s[i]=='1')x++;
    if(x == s.length())cout<<"YES";
    else cout<<"NO";
}