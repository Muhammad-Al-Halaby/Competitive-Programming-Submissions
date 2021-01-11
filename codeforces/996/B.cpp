#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int n,mini = INT_MAX,ans;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){

        cin >> a[i];
         mini = min(a[i],mini);
    }
    for(int i = mini%n,t=mini ;;i++,t++){
        if(a[i] - t <= 0){cout << i+1 ;break;}
        if(i == n-1)i = -1;
    }

}