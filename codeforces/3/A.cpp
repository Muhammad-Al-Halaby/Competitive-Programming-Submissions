#include <iostream>

using namespace std;

int main(){
    int row1,row2,column1,column2;
    char c;

    cin >> c >> row1;
    if(c == 'a') column1 = 1;
    else if(c == 'b') column1 = 2;
    else if(c == 'c') column1 = 3;
    else if(c == 'd') column1 = 4;
    else if(c == 'e') column1 = 5;
    else if(c == 'f') column1 = 6;
    else if(c == 'g') column1 = 7;
    else if(c == 'h') column1 = 8;

    cin >> c >> row2;
    if(c == 'a') column2 = 1;
    else if(c == 'b') column2 = 2;
    else if(c == 'c') column2 = 3;
    else if(c == 'd') column2 = 4;
    else if(c == 'e') column2 = 5;
    else if(c == 'f') column2 = 6;
    else if(c == 'g') column2 = 7;
    else if(c == 'h') column2 = 8;

     int rows_moves,columns_moves,rmd=0,cmd=0;
     rows_moves = max(row1,row2) - min(row1,row2);
     if(row1-row2 < 0) rmd = 1;
     columns_moves = max(column1,column2) - min(column1,column2);
     if(column1-column2 < 0) cmd = 1;
   if(columns_moves == rows_moves) cout << rows_moves;
   else if(columns_moves > rows_moves || columns_moves < rows_moves) cout << max(columns_moves,rows_moves);
    else cout << max(columns_moves,rows_moves) - min(columns_moves,rows_moves);

     while(rows_moves != 0 || columns_moves != 0){
            cout << endl;
            if(columns_moves > 0 && cmd == 1) {columns_moves--;cout << "R";}
            if(columns_moves > 0 && cmd == 0) {columns_moves--;cout << "L";}
            if(rows_moves > 0 && rmd == 1) {rows_moves--;cout << "U";}
            if(rows_moves > 0 && rmd == 0) {rows_moves--;cout << "D";}
     }

}