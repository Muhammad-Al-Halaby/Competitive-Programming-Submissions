#include <iostream>
#include <string>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    int arr[5][5],row=0,column=0;
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                row = i;
                column = j;
            }
        }
    }

    cout << (max(row,2) - min(row,2)) + (max(column,2) - min(column,2)) << endl;
}