#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int k,n=0,st;
    cin >> k;
    string arr[] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i = 0;i<12;i++)
        if(arr[i] == s){n = i+1;break;}
    st = k + n;
    while(st > 12) st -= 12;
    cout << arr[st-1];
}