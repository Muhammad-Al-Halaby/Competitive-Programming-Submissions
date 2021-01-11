#include <bits/stdc++.h>
using namespace std;
int main(){
    char arr[4][4];
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            int b=0,w=0;
            if(i+1 < 4 && i+1 < 4 && j + 1 < 4){
                if(arr[i][j]=='#')b++;
                else if(arr[i][j]=='.')w++;
                if(arr[i][j+1]=='#')b++;
                else if(arr[i][j+1]=='.') w++;
                if(arr[i+1][j]=='#')b++;
                else if(arr[i+1][j]=='.') w++;
                if(arr[i+1][j+1]=='#')b++;
                else if(arr[i+1][j+1]=='.') w++;
            }
            if(w >= 3 || b >= 3){cout << "YES";return 0;}
        }
    }
    cout << "NO";
}