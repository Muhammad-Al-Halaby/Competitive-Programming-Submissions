#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,q;
    cin >> n;
    int prices[n];
    for(int i = 0;i<n;i++)cin>>prices[i];
    sort(prices,prices+n);
    cin >> q;
    for(int i = 0;i<q;i++){
        int x;
        cin >> x;
        int counter = upper_bound(prices,prices+n,x)-prices;
        cout << counter << endl;
    }
}