#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();
    string s;
    cin >> s;
    vector<int> chars[27];
    for(int i = 0;i<s.length();i++){
        chars[s[i]-'a'].push_back(i);
    }


    int ans = INT_MAX;
    for(int c = 0;c <= 26;c++){
        int result = 0;
        for(int i = 0;i < chars[c].size();i++){
            if(i == 0)
                result = max(result,chars[c][i]+1);
            if(i == chars[c].size()-1)
                result = max(result,abs((int)s.length()-chars[c][i]));
            if(i+1 < chars[c].size())
                result = max(result,abs(chars[c][i]-chars[c][i+1]));
        }
        if(result)ans = min(ans,result);
    }
    cout << ans;
}