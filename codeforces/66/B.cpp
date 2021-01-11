#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans = 0;
    cin >> n;
    int h[n];
    for(int i = 0;i<n;i++)
        cin >> h[i];
    for(int i = 0;i<n;i++){
        int l = 0,r=0;
        for(int j = i-1;j >= 0 && h[j] <= h[i] && h[j] <= h[j+1];j--,l++);
        for(int j = i+1;j < n && h[j] <= h[i] && h[j] <= h[j-1];j++,r++);
        ans = max(ans,l+r+1);
    }
    cout << ans;
}
