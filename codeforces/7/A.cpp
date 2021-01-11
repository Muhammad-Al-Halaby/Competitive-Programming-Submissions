#include <iostream>
#include<cstdio>

using namespace std;

int main(){
    char arr[8][8];
    char rev_arr[8][8];
    char temp;

    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            temp = getchar();
            if(temp == '\n') temp = getchar();
          arr[i][j] =  temp;
         }
    }

    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            for(int k =0;k<8;k++){
                    rev_arr[j][k]=arr[k][j];
            }
        }
    }

    int column_b = 0,row_b = 0;
    int amount = 0;

    for(int i =0;i<8;i++){
        row_b = 0;
        for(int j =0;j<8;j++){
            if(arr[i][j] == 'B')
                row_b++;
        }
        if(row_b == 8)amount++;
    }

    if(amount < 8){
        for(int i =0;i<8;i++){
            column_b = 0;
            for(int j =0;j<8;j++){
                if(rev_arr[i][j] == 'B')column_b++;
            }
                if(column_b == 8)amount++;
        }
    }

    cout << amount;
}