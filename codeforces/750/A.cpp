#include <bits/stdc++.h>
#define OnlineJudge
using namespace std;
#define loop(n) for(int i = 0;i<n;i++)
typedef long long ll;
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}
int calc_time(int i, int k){
    int total = 5 * (i*(i+1)/2) + k;
    if(240-total>=0)return 1;
    return 0;
}
int main(){
   init();
   int n,k;
   cin >> n >> k;
   int l = 0;
   int r = n;
   int mid;
   int maxi = 0;
   while(l<r){
       mid = l+(r-l+1)/2 ;
       if(calc_time(mid,k) == 1){
            maxi = mid;
            l = mid;
       }
       else{
        r = mid - 1;
       }
   }
   cout << maxi;
}