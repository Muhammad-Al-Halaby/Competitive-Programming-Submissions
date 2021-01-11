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


char diff(char x){
    for(char c = '1';c <= '9';c++)  if(c != x)  return c;
}

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int j = 0, p = 0;
        for(int i = 0;i < 9;i++){
            string s;   cin >> s;
            s[j] = diff(s[j]);
            j += 3;
            if(j >= 9){
                p++;
                j = p;
            }
            cout << s << endl;
        }
    }
}