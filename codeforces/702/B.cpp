#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second


typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1e9+7;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int fastPow(int b, int e){
    if(e == 0)return 1;
    int ans = fastPow(b,e/2);
    ans *= ans;
    if(e & 1) ans *= b;
    return ans;
}

 int main(){
     init();

     int n;
     ll ans = 0;
     int powers[32];
     map<int, int> mp;

     for(int i = 0;i < 32;i++)
        powers[i] = fastPow(2,i);

     cin >> n;

     for(int i = 0;i<n;i++){
         int x;
         cin >> x;
         if(!i);
         else for(int i = 0;i < 32;i++)
            if(powers[i] > x && mp[powers[i]-x])
                ans += mp[powers[i]-x];
         mp[x]++;
     }
     cout << ans;
}
