#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,ans=0;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        string x;
        cin >> x;
        sort(x.begin(),x.end());
        set<int> ks;
        int counter=0;
        
        for(int i = 0;i<x.length();i++)
            ks.insert(x[i]-'0');
            
        for(set<int>::iterator it=ks.begin();it!=ks.end();it++)
            if(*it<=k)counter++;
        
        if(counter==k+1)ans++; 
    }
    cout << ans;
}