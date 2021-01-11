#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;
            cin >> c;
            arr[i][j]=c-'0';
        }
    }
    int cntr=1;
    for(int i = 0;i<n;i++){
            int counter=0;
            for(int j = 0;j<m;j++){
                if(arr[i][0]== arr[i][j])counter++;
            }
            if(i+1 <= n-1 && arr[i][0] != arr[i+1][0])cntr++;
            if(counter!=m){cout << "NO";return 0;}
            if(i == n-1 && cntr != n){cout << "NO";return 0;}
    }
    cout << "YES";
}
