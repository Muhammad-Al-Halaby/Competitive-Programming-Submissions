#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,dig=true,rest=true;
    char c=' ',o=' ';
    cin >> n;
    char arr[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
            if(c == ' '){c=arr[i][j];continue;}
            if(o == ' ')o=arr[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==j && arr[i][j] != c)dig=false;
            else if(i==j && arr[i][n-1-j] != c)dig=false;
            if(i != j && i+j != n-1 && arr[i][j] != o)rest=false;

        }
    }
    if(dig && rest && c != o)cout << "YES";
    else cout << "NO";
}