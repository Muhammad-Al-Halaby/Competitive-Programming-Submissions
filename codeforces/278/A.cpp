#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s,t,sum=0,d=0;
    cin >> n;
    int stations[n];
    for(int i = 0;i<n;i++){cin >> stations[i];sum+=stations[i];}
    cin >> s >> t;
    int maxi=max(s,t)-2;
    int mini=min(s,t)-1;
    for(int i = mini;i<=maxi;i++)d+=stations[i];
    cout << min(d,sum-d);
}