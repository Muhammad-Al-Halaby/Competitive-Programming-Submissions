#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int r,c,rs=0,cls=0;
    int rows[11] = {0};
    int cols[11] = {0};

    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            char c;
            cin >> c;
            if(c == '.')rows[i]++,cols[j]++;
            if(cols[j] == r)cls++;
        }
        if(rows[i] == c)rs++;
    }

    cout << (rs * c + cls * r) - (rs * cls);
}