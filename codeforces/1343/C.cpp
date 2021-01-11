#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[n];

        int fn = -1, fp = -1;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }


        int i = 0;

        ll sum = 0;
        while(i < n){
            //find mx pos
            int mx = -OO;
            while(i < n && a[i] > 0){
                mx = max(mx, a[i]);
                i++;
            }

            if(mx != -OO)   sum += mx;

            mx = -OO;
            while(i < n && a[i] < 0){
                mx = max(mx, a[i]);
                i++;
            }

            if(mx != -OO)   sum += mx;
        }

        cout << sum << '\n';
    }
}