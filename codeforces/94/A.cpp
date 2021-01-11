#include <bits/stdc++.h>
using namespace std;
int main() {
    string arr[11];
    for(int i = 0;i<11;i++)cin >> arr[i];
    for(int i = 0;i<80;i+=10){
        string sub = arr[0].substr(i,10);
        for(int i = 1;i<11;i++)if(sub==arr[i])cout<<i-1;
    }
}