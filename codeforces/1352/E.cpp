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

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;

        int a[n];
        for(int i = 0;i < n;i++)    cin >> a[i];

        if(n < 3){
            cout << 0 << '\n';
            continue;
        }

        int ans = 0;
        for(int i = 0;i < n;i++){
            int x = a[i], sum = 0;
            int l = 0, r = 0;
            while(l <= r){
                if(sum > x){
                    sum -= a[l++];
                }
                else{
                    if(r == n)  break;
                    sum += a[r++];
                }

                if(sum == x){
                    if(r - l >= 2){
                        ans++;
                        break;
                    }
                    sum -= a[l++];
                }
            }
        }

        cout << ans << '\n';
    }

}