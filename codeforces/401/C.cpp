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

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m;  cin >> n >> m;

    if(n - m > 1)   return cout << -1, 0;
    if(m > (n + 1) * 2) return cout << -1, 0;


    string s = "";
    int mn = min(n, m);
    n -= mn, m -= mn;
    while(mn--)   s += "01";

    if(m >= 2)  s = "11" + s, m -= 2;
    else if(m == 1) s = "1" + s, m--;

    for(int i = 0;i < s.size();i++){
        cout << s[i];
        if(m && s[i] == '1'){
            if(i + 1 < s.size() && s[i+1] == '1')   continue;
            if(i && s[i-1] == '1')  continue;

            cout << 1, m--;
        }
    }

    if(n)   cout << 0;
    while(m-- > 0)  cout << 1;
}