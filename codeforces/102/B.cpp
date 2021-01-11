#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum=0,cnt=-1;
    char digit;
    while(cin >> digit){
        sum += digit-'0';
        cnt++;
    }
    if(cnt > 0)cnt=1;
    while(sum >= 10){
        int nsum = 0;
        while(sum){
            nsum += sum%10;
            sum /= 10;
        }
        sum = nsum;
        cnt++;
    }
    cout << cnt;
}
