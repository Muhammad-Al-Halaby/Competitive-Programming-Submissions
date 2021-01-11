#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int b[n];
    for(int i=0;i<n;i++){cin >> b[i];}
    int s;
    cin >> s;
    for(int i = 0;i<s;i++){
        int x,y;
        cin >> x >> y;
        x--;
        if(x-1>=0)b[x-1]+=y-1;
        if(x+1<=n-1)b[x+1]+=b[x]-y;
        b[x]=0;
    }
    for(int i = 0;i<n;i++)
        cout << b[i] << endl;
}