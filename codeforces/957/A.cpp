#include <bits/stdc++.h>
#define OnlineJudge
using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}
int main(){
    init();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i<n-1;i++){
        if(s[i] != '?' && s[i] == s[i+1]){
            cout << "No";
            return 0;
        }
    }
    int h=0;
    for(int i = 0;i<n;i++){
        if(i && i+1 < n && s[i] == '?' && s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]);
        else if(s[i] == '?'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}