#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int dist = 0;
    string s,t;
    cin >> s >> t;
    for(int i = 0;i<s.size();i++)
        dist += s[i] != t[i];
    if(dist % 2)
        return cout << "impossible", 0;
    int r = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == t[i])
            cout << s[i];
        else{
            int a = s[i] - '0', b = t[i] - '0';
            if(r)cout << (a ^ 1);
            else cout << (b ^ 1);
            r ^= 1;
        }
    }
}