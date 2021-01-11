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

const int N = 59, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int n;  cin >> n;

    int fr[n][26] = {0};
    int ok[26] = {0};
    for(int i = 0;i < n;i++){
        string s;   cin >> s;
        for(int j = 0;j < s.size();j++)
            fr[i][s[j] - 'a']++;
        for(int j = 0;j < 26;j++)   ok[j] += (fr[i][j] > 0);
    }


    for(int i = 0;i < 26;i++){
        if(ok[i] != n)  continue;
        int mn = OO;
        for(int j = 0;j < n;j++)    mn = min(mn, fr[j][i]);
        while(mn--) cout << char('a'+ i);
    }
}