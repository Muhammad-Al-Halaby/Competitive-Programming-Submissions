#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,x,d=0;
    cin >> n >> x;
    while(n--){
        char c;
        int m;
        cin >> c >> m;
        if(c == '+')x+=m;
        else{
            if(m > x)d++;
            else x-=m;
        }
    }
    cout << x << " " << d;
}