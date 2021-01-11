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

bool check(string n){
    int ones = 0;
    for(char d : n){
        if(d-'0' == 1)
            ones++;
        else if(ones > 1 || d - '0' != 0)
            return 0;
    }
    if(ones > 1)
        return 0;
    return 1;
}
int main(){
    init();
    int n,digits = 0,zeros=0;
    cin >> n;
    string non = "1";

    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        if(check(s)){
            if(s[0]-'0' == 0)zeros=1;
            else digits += s.length()-1;
        }
        else
            non = s;
    }
    if(zeros)
        cout << 0;
    else{
        cout << non;
        for(int i = 0;i<digits;i++)
            cout << 0;
    }
}