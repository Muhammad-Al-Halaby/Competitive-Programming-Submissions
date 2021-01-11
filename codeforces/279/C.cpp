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

const int N = 1e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int a[N], incr[N], decr[N];
int main(){
    init();

    int n, q;   cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i == 1)  a[0] = a[i];

        incr[i] = ((a[i] > a[i-1]) ? 1 : 0) + incr[i - 1];
        decr[i] = ((a[i] < a[i-1]) ? 1 : 0) + decr[i - 1];
    }
//
//    for(int i = 1;i <= n;i++)
//        cout << incr[i] << " ";
//    cout << endl;
//    for(int i = 1;i <= n;i++)
//        cout << decr[i] << " ";
//    cout << endl;

    for(int i = 0;i < q;i++){
        int l, r;   cin >> l >> r;

        int x = lower_bound(incr + l, incr + r + 1, incr[r]) - incr;
        int y = upper_bound(decr + l, decr + r + 1, decr[l]) - decr - 1;

//        cout << x << " " << y << " ";

        if(x <= y)
            cout << "Yes\n";
        else
            cout << "No\n";

    }
}