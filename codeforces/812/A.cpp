#include<bits/stdc++.h>
using namespace std; 

int main() {
    int arr[4][4];
    for(int i = 0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    bool ans=0;
    for(int i =0;i<4;i++){
        if(arr[i][3]==1){
            for(int j=0;j<3;j++)if(arr[i][j]==1)ans=1;
            if(arr[(i+1)%4][0]==1)ans=1;
            if(arr[(i+2)%4][1]==1)ans=1;
            if(arr[(i+3)%4][2]==1)ans=1;
        }
    }
    if(ans)cout << "YES";
    else cout << "NO";
}