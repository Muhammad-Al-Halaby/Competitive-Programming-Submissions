#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    char c = 'a';
    cin >> n >> k;
    while(n--){
        cout << c;
        c++;
        if(c=='a'+k)c='a';
    }
}