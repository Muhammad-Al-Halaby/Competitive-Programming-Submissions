#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j>= m)
        return 0;
    return 1;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int n,m;
    char c;
    cin >> n >> m >> c;
    char arr[n][m];
    set<char> s;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] == c){
                for(int k = 0;k<4;k++){
                    if(valid(i+dy[k],j+dx[k],n,m) && arr[i+dy[k]][j+dx[k]] != '.' && arr[i+dy[k]][j+dx[k]] != c)
                        s.insert(arr[i+dy[k]][j+dx[k]]);
                }
            }
        }
    }
    cout << s.size();
}
