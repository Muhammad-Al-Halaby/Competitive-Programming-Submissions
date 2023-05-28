#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }

        for(int i = 0;i < n;i++){
            cout << n - (a[i] - 1) << " ";
        }
        cout << '\n';
    }
}