#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int fr[10000];

int main(){
    init();
    /* Sometimes you win, sometimes you learn */
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++)fr[j] = 0;
        fr[i]++;
        int next = arr[i-1];
        while(true){
            fr[next]++;
            if(fr[next] == 2)break;
            next = arr[next-1];
        }
        cout << next << " ";
    }
}