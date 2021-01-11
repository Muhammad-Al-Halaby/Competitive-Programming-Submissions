#include <bits/stdc++.h>

using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n, zeros = 0,ones = 1023,andd=1023,orr=0,xorr=0;
    cin >> n;
    int commands[n][2];
    for(int i = 0;i<n;i++){
        char c;
        int x;
        cin >> c >> x;
        if(c == '^'){
            zeros ^= x;
            ones ^= x;
        }
        else if(c == '&'){
            zeros &= x;
            ones &= x;
        }
        else if(c == '|'){
            zeros |= x;
            ones |= x;
        }
        commands[i][0] = c;
        commands[i][1] = x;
    }

    for(int i = 0;i<10;i++){
         bool zbit = 1 & (zeros >> i);
         bool obit = 1 & (ones >> i);
         if(zbit == obit && obit)orr |= (1 << i);
         if(zbit == obit && !obit)andd &= ~(1 << i);
         if(zbit != obit && zbit)xorr |= (1 << i);
         if(zbit != obit && !zbit)andd |= (1 << i);
    }
    if(n > 5){
        cout << 3 << '\n';
        cout << "| " << orr << '\n';
        cout << "& " << andd << '\n';
        cout << "^ " << xorr << '\n';
    }
    else{
        cout << n << '\n';
        for(int i = 0;i<n;i++)
            cout << char(commands[i][0]) << " " << commands[i][1] << '\n';
    }
}