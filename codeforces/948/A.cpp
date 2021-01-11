#include <bits/stdc++.h>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main(){
    cin.tie(0);
	cin.sync_with_stdio(0);

    int r,c;
    cin >>r >> c;
    char arr[r][c];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
                 if(arr[i][j] == 'S'){
                    for(int k = 0;k<4;k++){
                        if(i+dy[k] >= 0 && i+dy[k] < r && j+dx[k] >= 0 && j+dx[k] < c){
                            if(arr[i+dy[k]][j+dx[k]] == 'W'){
                                cout << "No";
                                return 0;
                            }
                        }
                    }
                 }
        }
    }

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                 if(arr[i][j] == 'S'){
                    for(int k = 0;k<4;k++){
                        if(i+dy[k] >= 0 && i+dy[k] < r && j+dx[k] >= 0 && j+dx[k] < c){
                            if(arr[i+dy[k]][j+dx[k]] == '.'){
                                arr[i+dy[k]][j+dx[k]] = 'D';
                            }
                        }
                    }
                 }
            }
        }
    cout << "Yes" << endl;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

}