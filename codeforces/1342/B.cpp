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

const int N = 1e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;
        int ones = 0, zeros = 0;
        for(int i = 0;i < s.size();i++){
            ones += s[i] == '1';
            zeros += s[i] == '0';
        }

        if(!zeros || !ones){
            cout << s << '\n';
            continue;
        }

        string t = "";
        int x = ones + zeros;
        while(x){
            t += "10";
            x--;
        }

        cout << t << '\n';
    }


}