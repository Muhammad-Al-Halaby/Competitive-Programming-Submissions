#include "bits/stdc++.h"

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

const int N = 250, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void go(int tc = 0){
    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int k = j + 1;k < n;k++){
                int b[] = {a[i], a[j], a[k]};
                sort(b, b + 3);
                if(b[0] == b[1] || b[1] == b[2])
                    continue;
                if(b[0] + b[1] > b[2])
                    ans++;
            }
        }
    }

    cout << ans;
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}