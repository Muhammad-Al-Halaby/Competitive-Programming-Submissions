#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    double arr[n];
    for(int i = 0;i<n;i++){
        double x,y;
        cin >> x >> y;
        arr[i] = x/y;
    }
    sort(arr,arr+n);
    printf("%.6f\n",arr[0] * m);
}