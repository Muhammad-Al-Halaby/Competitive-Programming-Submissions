#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2000, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

string s[N];
map<string, int> mp;
char st[] = {'S','E','T'};
inline char getthird(char a, char b){
    if(a == b)  return a;
    for(int i = 0;i < 3;i++)    if(st[i] != a && st[i] != b)    return st[i];
}
int main(){
    init();

    int n, k;  cin >> n >> k;

    for(int i = 0;i < n;i++){
        cin >> s[i];
        mp[s[i]]++;
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        int &x = mp[s[i]];  x--;
        for(int j = i + 1;j < n;j++){
            string c = "";
            int &y = mp[s[j]];  y--;
            for(int u = 0;u < k;u++){
                c += getthird(s[i][u], s[j][u]);
            }
            if(mp.count(c)){
                if(mp[c] > 0)   ans++;
            }
            y++;
        }
        x++;
    }

    cout << ans / 3;

}





