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

 int main(){
     init();
     int n,ans = 1, l = 0, last;
     cin >> n;
     for(int i = 0;i<n;i++){
         int x;
         cin >> x;
         if(!i);
         else if(x > last)ans = max(ans, i - l + 1);
         else l = i;
         last = x;
     }
     cout << ans;
}