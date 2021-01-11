#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n+1], sorted[n+1];
    arr[0] = 0;
    sorted[0] = 0;

    for(int i = 1;i<=n;i++){
        cin >> sorted[i];
        arr[i] = sorted[i] + arr[i-1];
    }
    sort(sorted,sorted+n+1);
    for(int i = 1;i<=n;i++){
        sorted[i] += sorted[i-1];
    }

    int m;
    cin >> m;
    for(int i = 0;i<m;i++){
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1)
            cout << arr[r] - arr[l-1] << endl;
        else
            cout << sorted[r] - sorted[l-1] << endl;
    }

}