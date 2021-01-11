#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,max=0;
    string winner;
    cin >> n;
    map<string,int>m;
    for(int i =0;i<n;i++){
        string x;
        cin >> x;
        m[x]++;
    }
    map<string,int>:: iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++)
    if((*iter).second > max){
        max=(*iter).second;
        winner=(*iter).first;
    }
    cout << winner;
}