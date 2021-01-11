#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,flats=0;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int w1,w2;
            cin >> w1 >> w2;
            if(w1 + w2 > 0)flats++;
        }
    }
    cout << flats;
}