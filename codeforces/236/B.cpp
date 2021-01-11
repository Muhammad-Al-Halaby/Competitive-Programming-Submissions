#include <bits/stdc++.h>
using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int fr[(int)1e6+5];

int divisors(int n){
    int total = 1;
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n%i == 0)n/=i,cnt++;
            total *= cnt + 1;
        }
    }
    if(n != 1)total *= 2;
    return total;
}
int main(){
    init();
    int a,b,c,ans = 0;
    cin >> a >> b >> c;
    for(int i = 1; i < a + 1;i++){
        for(int j = 1;j < b + 1;j++){
            for(int k = 1;k < c + 1;k++){
                fr[i * j * k]++;
            }
        }
    }

    for(int i = 1;i < 1e6 + 1;i++){
        if(fr[i])
            ans = ans % 1073741824 + (fr[i] * divisors(i)) % 1073741824;
    }
    ans %= 1073741824;

    cout << ans;
}