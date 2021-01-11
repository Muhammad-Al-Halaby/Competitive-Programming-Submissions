#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string x;
    cin >> x;
    for(int i = 0;i<m;i++){
        int l,r;
        char c1,c2;
        cin >> l >> r >> c1 >> c2;
        for(int j = l-1;j <= r-1;j++)
            if(x[j] == c1)x[j]=c2;

    }
    cout << x;
}