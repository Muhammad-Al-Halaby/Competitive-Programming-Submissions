#include <bits/stdc++.h>
using namespace std;

string calcMinimum(int m,int s){
    int f = m;
    string minimum = "";
    int digit = 0;
    while(s){

        if(s-digit <= (m-1) * 9 && !(m == f && digit == 0 || m == 1 && digit == 0)){
            minimum += digit+'0';
            s-=digit;
            m--;
            digit = 0;
        }
        else{
            digit++;
        }
    }
    for(int i = 0;i<m;i++)
        minimum.insert(1 && m!=f,"0");
    return minimum;
}

string calcMaximum(int m,int s){
    string maximum = "";
    int digit = 9;
    while(s){
        if(s-digit >= 0){
            maximum += digit+'0';
            s-=digit;
            m--;
        }
        else{
            digit--;
        }
    }
    for(int i = 0;i<m;i++)
        maximum += '0';
    return maximum;
}

int main(){
    int m,s;
    cin >> m >> s;
    if(m * 9 < s || (m > 1 && s == 0))cout << -1 << " " << -1;
    else{

        cout << calcMinimum(m, s) << " " << calcMaximum(m, s);
    }
}