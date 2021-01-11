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

const int N = 1e5, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc){
    int n;  cin >> n;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    // Counting Inversions
    int inv = 0;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
            inv += a[i] > a[j];

    int ans = inv & 1;

    int m;  cin >> m;
    for(int i = 0;i < m;i++){
        int l, r;   cin >> l >> r;

        int len = r - l + 1;
        int b = len * (len - 1) / 2;
        ans ^= b & 1;
        cout << (ans & 1 ? "odd" : "even") << '\n';
        /*
            b = number of pairs in [l, r]
            before reverse:
            a = number of inversions in [l, r]
            after reverse:
            b - a = number of inversions in [l, r]

            checking parity of b is enough.
            if(a is even && b is odd)  reverse the parity;
            if(a is odd && b is odd) reverse the parity;
            otherwise parity stays the same.
        */
    }

}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)  go(tc++);
}