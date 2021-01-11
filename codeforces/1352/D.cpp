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
        int p = 1, alice = a[0], bob = 0, prev = a[0], l = 1, r = n - 1;;
        while(l <= r){
            if(p & 1){
                int sum = 0;
                while(r >= l && sum <= prev){
                    sum += a[r--];
                }
                bob += sum;
                prev = sum;
            }
            else{
                int sum = 0;
                while(l <= r && sum <= prev){
                    sum += a[l++];

                }
                alice += sum;
                prev = sum;
            }
            p++;
        }

        cout << p << " " << alice << " " << bob << '\n';
    }

}
