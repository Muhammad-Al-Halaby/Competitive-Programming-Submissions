#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,l=0,ans=0;
    cin >> n >> a;
    int t[n];
    for(int i = 0;i<n;i++)
        cin >> t[i];
    a--;
    for(int i = 0;i<n;i++){
        if(a-i >= 0 && a+i < n && t[a-i] + t[a+i] == 2)ans+=2;
        else if(a-i >= 0 && a+i >= n)ans+= t[a-i];
        else if(a+i < n && a-i < 0)ans+= t[a+i];
    }
    if(t[a] == 1)ans--;


    cout << ans;
}
