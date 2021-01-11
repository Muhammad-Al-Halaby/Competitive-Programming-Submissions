#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s,ans;
    cin >> s;
    for(int i = 0;i<n;i++){
        if(i%2 == 0)
            ans = s[i] + ans;
        else
            ans += s[i];
    }
    if(n % 2 != 0)
        reverse(ans.begin(),ans.end());
    cout << ans;
}