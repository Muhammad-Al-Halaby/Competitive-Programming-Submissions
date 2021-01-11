#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,sum=0;
    cin >> n;
    while(n--){
        string x;
        cin >> x;
        if(x=="Tetrahedron")sum+=4;
        else if(x=="Cube")sum+=6;
        else if(x=="Octahedron")sum+=8;
        else if(x=="Dodecahedron")sum+=12;
        else if(x=="Icosahedron")sum+=20;
    }
    cout << sum;
}