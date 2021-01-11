#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long long list1[5]={0};
    long long list2[5]={0};
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        list1[i%5]++;
    }
    for(int i = 1;i<=m;i++){
        list2[i%5]++;
    }
    cout << list1[0]*list2[0] + list1[1]*list2[4] + list1[4]*list2[1] + list1[2] * list2[3] + list1[3] * list2[2];
}