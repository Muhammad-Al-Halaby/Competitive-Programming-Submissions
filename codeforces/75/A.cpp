#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int removeZeros(int x){
    int res = 0, i = 1;
    while(x){
        int lastDigit = x % 10;
        x /= 10;
        res += i * lastDigit;
        if(lastDigit)
            i *= 10;
    }
    return res;
}

int main(){
    init();
    int a,b;
    cin >> a >> b;
    if(removeZeros(a) + removeZeros(b) == removeZeros(a+b))
        cout << "YES";
    else
        cout << "NO";

}