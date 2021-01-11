#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int a,b,c,x,y,z,sum1,sum2,h,m;
    char d;
   
    cin >> a >> d >> b;
    cin >> x >> d >> y;
   
    sum1 = a * 60 + b;
    sum2 = x * 60 + y;
   
    int diff = abs(sum2-sum1);
    if(sum2 >= sum1) diff = 1440 - diff;
   
    h = diff/60;
    m = (diff%60);
    if(h == 24) h = 0;
    
    cout << (h<10 ? "0" : "") << h << ":" << (m<10 ? "0" : "") << m;
}