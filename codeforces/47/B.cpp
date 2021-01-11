#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans[] = {"CBA", "BCA", "CAB", "ACB", "BAC", "ABC"};
    string odds[] = {"ABA", "ACA", "BBA", "BBC", "ACC", "BCC"};
    string s = "...";

    for(int i = 0;i<3;i++){
        string x;
        cin >> x;
        if(x[0] + x[2] == 'A' + 'B'){
            if(x[1] == '>')s[0] = x[0];
            else s[0] = x[2];
        }
        else if(x[0] + x[2] == 'B' + 'C'){
            if(x[1] == '>')s[1] = x[0];
            else s[1] = x[2];
        }
        else if(x[0] + x[2] == 'A' + 'C'){
            if(x[1] == '>')s[2] = x[0];
            else s[2] = x[2];
        }
    }
    for(int i = 0;i<6;i++){
        if(s == odds[i]){
            cout << ans[i];
            return 0;
        }
    }
    cout << "Impossible";
}
