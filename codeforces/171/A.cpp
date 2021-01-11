#include<bits/stdc++.h>
using namespace std; 

int power(int p){
    int res=1;
    for(int i = 1;i<=p;i++)res*=10;
    return res;
}
int main(){
    int a;
    string b;
    cin >> a >> b;
    for(int i = b.length()-1;i>=0;i--)a+=(b[i]-'0')*power(i);
    cout << a;
} 