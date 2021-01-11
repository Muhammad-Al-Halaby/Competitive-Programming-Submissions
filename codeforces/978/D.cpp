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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n;  cin >> n;

    int a[n];

    for(int i = 0;i < n;i++)    cin >> a[i];

    if(n <= 2)  return cout << 0, 0;

    int b[n], ans = OO;
    for(int i = -1;i <= 1;i++){
        for(int j = -1;j <= 1;j++){
            int d = (a[1] + j) - (a[0] + i);
            b[1] = a[1] + j;

            int ok = 1, op = (j != 0) + (i != 0);
            for(int k = 2;k < n;k++){
                if(abs(a[k] - (b[k - 1] + d)) > 1){
                    ok = 0;
                    break;
                }

                op += abs(a[k] - (b[k - 1] + d));

                b[k] = b[k - 1] + d;
            }
            if(!ok) continue;
            ans = min(ans, op);
        }
    }

    cout << (ans == OO ? -1 : ans);
}
