#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char arr[n][m];
    char ans[n][m];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
            ans[i][j]=arr[i][j];
        }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x = arr[i][j];
            for(int k = 0;k<m;k++)if(k != j && arr[i][k]==x){ans[i][k]='1';ans[i][j]='1';}
            for(int k = 0;k<n;k++)if(k != i && arr[k][j]==x){ans[k][j]='1';ans[i][j]='1';}
        }
    }
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(ans[i][j]!='1')cout << ans[i][j];
}