#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    long long maximum = -1e18, idx = 0;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0;i<n;i++)cin >> a[i];
    for(int i = 0;i<m;i++)cin >> b[i];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(maximum < (long long) a[i] * b[j])idx = i;
            maximum = max(maximum, (long long) a[i] * b[j]);
        }
    }
    maximum = -1e18;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i != idx)
                maximum = max(maximum, (long long) a[i] * b[j]);
        }
    }
    cout << maximum;
}