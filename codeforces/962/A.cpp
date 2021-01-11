#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
  ll n,sum=0;
  cin >> n;
  ll arr[n+1]={0};
  for(int i = 1;i<=n;i++){
    int x;
    cin >> x;
    arr[i] = x;
    sum += x;
  }
  for(int i = 1;i<=n;i++){
    arr[i] += arr[i-1];
    if(arr[i] >= (sum+1)/2){
      cout << i;
      return 0;
    }
  }
}