#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans=0;
    string s;
    cin >> s;
    for(int i = 0;i<s.length();i++){
        if( s[i] == 'u' || s[i] =='a'|| s[i] == 'e' || s[i] == 'i' || s[i] == 'o')ans++;
        else if (s[i] < 'a' && (s[i]-'0') % 2 != 0)ans++;
    }
    cout << ans;
}
