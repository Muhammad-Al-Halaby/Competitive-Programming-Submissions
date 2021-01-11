#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main(){
    int n;
    cin >> n;
    int i = n;
    while(n--){
        int x;
        cin >> x;
        arr[x]=1;
        while(arr[i])cout << i << " ",i--;
        cout << '\n';
    }
}