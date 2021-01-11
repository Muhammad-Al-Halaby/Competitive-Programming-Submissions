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

const int N = 2e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();


    int t;  cin >> t;
    while(t--){
        string a, b;    cin >> a >> b;

        int fr[26] = {};
        int n = a.size(), m = b.size();
        for(int i = 0;i < n;i++){
            fr[a[i] - 'A']++;
        }

        string s = a;   sort(s.begin(), s.end());
        if(s >= b){
            cout << "---" << '\n';
            continue;
        }

        for(int i = 0;i < min(n, m);i++){
            if(a[i] < b[i]) break;

            fr[a[i] - 'A']--;

            int j = 0, ok = 0;
            for(j = 0;j <= (b[i] - 'A');j++){
                if(fr[j]){
                    ok = 1;
                    break;
                }
            }

            if(ok){
                char c = 'A' + j;
                if(c == a[i])   continue;
                bool sw = 0;
                for(int j = n - 1;j > i;j--){
                    if(a[j] == c){
                        swap(a[i], a[j]);
                        sw = 1;
                        break;
                    }
                }
                if(sw)  break;
            }


        }

        if(a < b)
            cout << a << '\n';
        else
            cout << "---" << '\n';
    }
}