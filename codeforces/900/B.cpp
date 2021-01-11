#include <bits/stdc++.h>
using namespace std;

int main(){
    long double a,b,c,i=1;
    cin >> a >> b >> c;
    string x;
    vector<int> v;
    bool rep=false;
    while(true){
        a*=10;
        if(!v.empty())
            for(int i =0;i<v.size();i++)
                if(a==v[i]){rep=true;break;}
        if(rep){cout << -1;return 0;}
        v.push_back(a);
        int dec = (long long)a/b;
        x+= dec;
        a-=(dec*b);
        if(dec==c){cout << i;return 0;}
        i++;
    }
    if(c==0)cout << i;
    else cout << -1;
}