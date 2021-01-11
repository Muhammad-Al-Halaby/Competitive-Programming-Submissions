#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void go(int tc = 0){
    int n;  cin >> n;
    string s;   cin >> s;

    string p = "abacaba";
    int f = 1;
    for(int i = 0;i + 7 <= n;i++){
        string t = s;

        int ok = 1;
        for(int j = 0;j < 7;j++){
            if(t[i + j] == '?') t[i + j] = p[j];
                else if(t[i + j] != p[j])   ok = 0;
        }

        for(int j = 0;j < n;j++)
            if(t[j] == '?') t[j] = 'z';

        if(ok){
            int cnt = 0;
            for(int j = 0;j + 7 <= n;j++){
                string x = t.substr(j, 7);
                if(x == p)cnt++;
            }
            if(cnt == 1){
                f = 0;
                cout << "Yes\n" << t << '\n';
                break;
            }
        }

    }


    if(f)   cout << "No\n";
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
    cin >> t;
    while(t--)
        go(tc++);
}