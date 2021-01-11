#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>to;
    for(int i = 0;i<n;i++){
     int num;
     cin >> num;
     for(int j = 0;j<num;j++){
      int bulb;
      cin >> bulb;
      if(find(to.begin(),to.end(),bulb) == to.end())to.push_back(bulb);
      }
     }
    if(m == to.size())cout<<"YES";
    else cout<<"NO";
    
}