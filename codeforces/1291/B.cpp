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
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[n], b[n], c[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
            b[i] = c[i] = a[i];
        }

        //let's make it strictly dec
        int ok = 1;
        for(int i = 1;i < n;i++){
            if(b[i] < b[i - 1]) continue;
            b[i] = b[i - 1] - 1;
            if(b[i] == -1)  ok = 0;
        }

        if(ok){
            cout << "Yes\n";
            continue;
        }

        //let's make strictly inc then dec
        c[0] = 0;

        ok = 1;
        int k = -1;
        for(int i = 1;i < n;i++){
            if(c[i] <= c[i-1]){
                ok = 2;
                k = i;
                break;
            }
            c[i] = c[i - 1] + 1;
        }


        if(ok == 1){
            cout << "Yes\n";
            continue;
        }

        c[k - 1] = a[k - 1];
        ok = 1;
        for(int i = k;i < n;i++){
            if(c[i] < c[i - 1]) continue;
            c[i] = c[i - 1] - 1;
            if(c[i] == -1)  ok = 0;
        }

        if(ok){
            cout << "Yes\n";
            continue;
        }

        cout << "No\n";
    }
}









