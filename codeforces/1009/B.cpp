#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string s;   cin >> s;
    int n = s.size();

    int ones = 0;
    for(int i = 0;i < n;i++)
        ones += s[i] == '1';

    int two = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '2') while(ones > 0 && ones--)   cout << '1';
        if(s[i] != '1') cout << s[i];
    }

    while(ones > 0 && ones--)   cout << '1';
}
