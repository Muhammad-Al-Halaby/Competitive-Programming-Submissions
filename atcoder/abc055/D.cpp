#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 50, M = 500, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;
string  ss;

int nxt(int i){
    return i + 1 == n ? 0 : i + 1;
}

int prev(int i){
    return i - 1 == -1 ? n - 1 : i - 1;
}

char op(char c){
    return c == 'W' ? 'S' : 'W';
}

string check(int status){
    // 0 - SS, 1 - SW, 2 - WS, 3 - WW
    string s(n, '.');
    if(status == 0) s[0] = s[n - 1] = 'S';
    if(status == 1) s[0] = 'S', s[n - 1] = 'W';
    if(status == 2) s[0] = 'W', s[n - 1] = 'S';
    if(status == 3) s[0] = s[n - 1] = 'W';

    for(int i = 0;i < n;i++){
        if(s[i] == 'S'){
            if(ss[i] == 'o'){
                if(s[nxt(i)] == '.')    s[nxt(i)] = s[prev(i)];
                else if(s[nxt(i)] != s[prev(i)])    return "-1";
            }
            else{
                if(s[nxt(i)] == '.')    s[nxt(i)] = op(s[prev(i)]);
                else if(s[nxt(i)] == s[prev(i)])    return "-1";
           }
        }
        else{
            if(ss[i] == 'x'){
                if(s[nxt(i)] == '.')    s[nxt(i)] = s[prev(i)];
                else if(s[nxt(i)] != s[prev(i)])    return "-1";
            }
            else{
                if(s[nxt(i)] == '.')    s[nxt(i)] = op(s[prev(i)]);
                else if(s[nxt(i)] == s[prev(i)])    return "-1";
           }
        }
    }
    return s;
}

int main(){
    init();

    cin >> n >> ss;

    for(int i = 0;i <= 3;i++){
        string res = check(i);
        if(res != "-1")   return cout << res, 0;
    }

    cout << -1;
}