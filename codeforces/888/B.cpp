#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,r=0,l=0,u=0,d=0,ans=0;
    cin >> n;
    for(int i = 0;i<n;i++){
char c; 
cin>>c; 
if(c=='R') r++;
else if(c == 'L') l++;
else if(c == 'U') u++;
else d++;
}
    ans= min(r,l)*2+min(u,d)*2;
    cout<<ans;
}