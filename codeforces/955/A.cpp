#include <bits/stdc++.h>
#define OnlineJudge
using namespace std;

int main(){
    #ifndef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif
    double hh,mm,h,d,c,n;
    cin >> hh >> mm >> h >> d >> c >> n;
    double total = hh*60 + mm;
    double diff=0;
    if(total < 1200)diff = 1200 - total;
    else diff=0;
    double cost1 = ceil((h+diff*d)/n) * (c - (c*0.2));
    double cost2 = ceil(h/n) * (c);
    if(cost1 <= cost2)
        printf("%.4f",cost1);
    else
        printf("%.4f",cost2);
}