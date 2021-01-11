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

const int N = 1e5 + 9, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }



    int idx[n];

    int r[n + 1] = {0};
    for(int i = n - 1;i >= 0;i--){
        if(i + 1 < n && a[i] < a[i + 1])
            r[i] = r[i + 1] + 1;
        else
            r[i] = 1;
    }

    int l[n + 1] = {0};
    for(int i = 0;i < n;i++){
        if(i && a[i] > a[i - 1])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;
    }


    int ans = 0;
    for(int i = 0;i < n;i++){
        if(i == 0)
            ans = max(ans, 1 + r[i + 1]);
        else if(i == n - 1)
            ans = max(ans, 1 + l[i - 1]);

        else if(a[i - 1] + 1 < a[i + 1])
            ans = max(ans, l[i - 1] + 1 + r[i + 1]);
        else
            ans = max({ans, l[i - 1] + 1, 1 + r[i + 1]});
    }

    cout << ans;
}

int main(){
//    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)
        go(tc++);
}