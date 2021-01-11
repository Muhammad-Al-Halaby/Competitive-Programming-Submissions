#include<bits/stdc++.h>

using namespace std;

int rows[2001];
int columns[2001];

int main(){
    int n, m, k,ans=0;
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;cin >> x;
            if(x=='.'){
                rows[i]++;
                columns[j]++;
                if(rows[i] == k){
                    ans++;
                    rows[i] = k - 1;
                }
                if(columns[j] == k){
                    if(k != 1)ans++;
                    columns[j] = k - 1;
                }
            }
            else{
                rows[i] = 0;
                columns[j] = 0;
            }
        }
    }
    cout << ans;
}