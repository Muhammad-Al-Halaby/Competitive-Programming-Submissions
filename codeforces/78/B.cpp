#include <bits/stdc++.h>
using namespace std;

int main(){
    char arr[]="ROYGBIV";
    int n;
    cin >> n;
    for(int i = 0;i<n/7;i++)
        cout << arr;
    string ar[] = {"","G","YG","YGB","YGBI","YGBIV","YGBIVG"};
    if(n%7!=0)cout << ar[n%7];
}
