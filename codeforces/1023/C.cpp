#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,k,x,cnt=0;
    cin >> n >> k;
    x = (n - k) / 2;
    string s;
    cin >> s;
    stack<char> st;
    for(char c : s){
        if(c == '(')
            st.push(c);
        else{
            if(x){
                st.pop();
                x--;
            }
            else break;
        }
        cnt++;
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    for(cnt;cnt<s.size();cnt++)
        cout << s[cnt];
}