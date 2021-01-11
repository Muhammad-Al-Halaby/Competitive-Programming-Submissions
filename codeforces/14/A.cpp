#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m, mm[4]={49,49,0,0};
    cin >> n >> m;
    char arr[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == '*'){
                if(i < mm[0])
                    mm[0] = i;
                if(j < mm[1])
                    mm[1] = j;
                if(i > mm[2])
                    mm[2] = i;
                if(j > mm[3])
                    mm[3] = j;
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        bool p = 0;
        for(int j = 0;j<m;j++){
            if(i >= mm[0] && i <= mm[2] && j >= mm[1] && j <= mm[3]){
                cout << arr[i][j];
                p=true;
            }
        }
        if(p)cout << '\n';
    }
}