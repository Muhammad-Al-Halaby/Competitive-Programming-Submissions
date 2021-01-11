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

const int N = 109, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int k;  string s;   cin >> s >> k;
    int n = s.size();

    for(int i = 0;i < n;i++){
        char mx = '0';

        for(int j = i + 1;j < n;j++){
            if(s[j] > s[i] && (j - i) <= k && s[j] > mx){
                mx = s[j];
            }
        }

        if(mx <= s[i])  continue;

        int idx = -1;
        for(int j = i + 1;j < n;j++){
            if(s[j] == mx){
                idx = j;
                break;
            }
        }

        k -= (idx - i);
        while(idx > i) swap(s[idx], s[idx - 1]), idx--;
    }

    cout << s;
}
