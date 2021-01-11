#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int n,a,b,c,ans = 0;
    cin >> n >> a >> b >> c;
    for(int i = 0;i * a <= n;i++){
        for(int j = 0;j * b + i * a <= n;j++){
            int x = i,y=j,z=0;
            if((n-x*a-y*b) % c == 0)z = (n-x*a-y*b)/c;
            if(j * b + i * a + z * c == n)
                ans = max(ans, x+y+z);
        }
    }
    cout << ans;
}