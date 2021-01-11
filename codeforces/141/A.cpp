#include<bits/stdc++.h>
using namespace std; 

int main(){
    string x,y,z;
    cin >> x >> y >> z;
    int arr[26];
    for(int i = 0;i<26;i++)arr[i]=0;
    for(int i = 0;i<x.length();i++)arr[x[i]-'A']++;
    for(int i = 0;i<y.length();i++)arr[y[i]-'A']++;
    for(int i = 0;i<z.length();i++)arr[z[i]-'A']--;
    for(int i = 0;i<26;i++)if(arr[i] != 0){cout << "NO";return 0;}
    cout << "YES";
}