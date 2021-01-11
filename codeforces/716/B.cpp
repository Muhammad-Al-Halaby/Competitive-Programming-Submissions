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

const int N = 1e3 + 9, M = 12, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int fr[300];


char nxt(){
    for(char k = 'A';k <= 'Z';k++)
        if(fr[k] == 0)  return fr[k]++, k;
}
int main(){
    init();

    string s;   cin >> s;
    int n = s.size();
    for(int j = 0, i = 0;i < n;fr[s[i]]--, i++){
        while(j < n && j - i + 1 <= 26)fr[s[j]]++,j++;
        
        if(j - i < 26)  break;
        
        int ok = 1;
        for(int k = 'A';k <= 'Z';k++){
            if(fr[k] > 1)   ok = 0;
        }
        
        if(ok){
            for(int k = i;k < j;k++){
                if(s[k] == '?') s[k] = nxt();
            }
            for(int k = 0;k < n;k++){
                if(s[k] == '?') s[k] = 'A';
            }
            return cout << s, 0;
        }
    }

    cout << -1;
}