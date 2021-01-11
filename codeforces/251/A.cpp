#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main(){
   init();
   ll n,d,ans=0;
   cin >> n >> d;
   int arr[n];
   
   for(int i = 0;i < n;i++)
       cin >> arr[i];
    
   for(int i = 0;i<n-2;i++){
       int num_of_elem = upper_bound(arr,arr+n,arr[i] + d) - arr - i - 1;
       ll perm = 1;
       for(int i = num_of_elem;i > num_of_elem-2;i--){
           perm *= i;
       }
       perm /= 2;
       ans += perm;
   }
   cout << ans;
}