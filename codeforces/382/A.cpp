#include <bits/stdc++.h>
using namespace std;
int main(){
    string x,r,l,y;
    cin >> x >> y;
    r=x.substr(0,x.find('|'));l=x.substr(x.find('|')+1,x.length()-r.length()-1);
    int a,b,c,d;
    a=r.length();b=l.length();c=y.length();d=(max(a,b)-min(a,b));
    
    if(c-d >= 0 && (c-d) % 2 == 0){
        cout << r;
        if(a<b)for(int i = 0;i<d;i++)cout << y[i];
        for(int i = d;i<d+(c-d)/2;i++)cout << y[i];
        cout << '|';
        cout << l;
        if(b<a)for(int i = 0;i<d;i++)cout << y[i];
        if((c-d)/2!=0)for(int i = d+(c-d)/2;i<c;i++)cout << y[i];
    }
    else cout << "Impossible";
}