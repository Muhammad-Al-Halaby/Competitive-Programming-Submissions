#include <bits/stdc++.h>
using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    string s;
    cin >> s;
    vector<int> ab,ba;

    for(int i = 0;i<s.size();i++){
        if(s[i] == 'A' && s[i+1] == 'B')
            ab.push_back(i);
        else if(s[i] == 'B' && s[i+1] == 'A')
            ba.push_back(i);
    }

    bool ans = 0;

    for(int a : ab){
        for(int b : ba){
            if(a + 1 != b && b+1 != a)ans = 1;
            if(ans)break;
        }
    }
    if(ans)
        return cout << "YES", 0;
    cout << "NO";
}