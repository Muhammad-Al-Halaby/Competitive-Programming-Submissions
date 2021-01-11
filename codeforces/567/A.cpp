#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c[n];
    for(int i = 0;i<n;i++)cin >> c[i];
    for(int i = 0;i<n;i++){
        if(i == 0)
            cout << abs(c[i]-c[i+1]) << " " << abs(c[i]-c[n-1]) << endl;
        else if(i==n-1)
            cout << abs(c[n-1]-c[n-2]) << " " << abs(c[0]-c[n-1]) << endl;
        else
            cout << min(abs(c[i]-c[i+1]),abs(c[i]-c[i-1])) << " " << max(abs(c[i]-c[0]),abs(c[i]-c[n-1])) << endl;
    }
}
