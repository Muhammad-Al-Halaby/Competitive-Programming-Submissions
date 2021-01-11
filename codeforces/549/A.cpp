#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<iomanip>
#include<utility>
#include<numeric>
#include<set>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char arr[n][m];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin >> arr[i][j];

    int faces = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i != n-1 && j != m-1){
                int f=0,a=0,c=0,e=0;

                if(arr[i][j] == 'f')f++;
                else if(arr[i][j] == 'a')a++;
                else if(arr[i][j] == 'c')c++;
                else if(arr[i][j] == 'e')e++;

                if(arr[i][j+1] == 'f')f++;
                else if(arr[i][j+1] == 'a')a++;
                else if(arr[i][j+1] == 'c')c++;
                else if(arr[i][j+1] == 'e')e++;

                if(arr[i+1][j] == 'f')f++;
                else if(arr[i+1][j] == 'a')a++;
                else if(arr[i+1][j] == 'c')c++;
                else if(arr[i+1][j] == 'e')e++;

                if(arr[i+1][j+1] == 'f')f++;
                else if(arr[i+1][j+1] == 'a')a++;
                else if(arr[i+1][j+1] == 'c')c++;
                else if(arr[i+1][j+1] == 'e')e++;
                if(f > 0 && a > 0 && c > 0 && e > 0)faces++;
            }
        }
    }
    cout << faces;
}