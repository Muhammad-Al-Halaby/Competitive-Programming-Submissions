#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

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
    int ans = 0;
    string s;
    cin >> s;
    stack<char> st;
    for(char c : s){
        if(c == '(')
           st.push(c);
        else if(!st.empty())
            st.pop();
        else
            ans++;
    }
    ans+= st.size();
    cout << s.size()-ans;
}