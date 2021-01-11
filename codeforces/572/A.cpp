#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int na,nb,k,m,cnt=0;
    cin >> na >> nb >> k >> m;
    int a[na];
    for(int i = 0;i<na;i++)
        cin >> a[i];
    sort(a,a+na);
    for(int i = 0;i<nb;i++){
        int x;
        cin >> x;
        if(x > a[k-1])cnt++;
    }
    if(cnt >= m)
        cout << "YES";
    else
        cout << "NO";
}
