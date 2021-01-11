#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EPS 1e-9
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

double area(int x1, int y1, int x2, int y2,
                            int x3, int y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +
                x3 * (y1 - y2)) / 2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3,int y3, int x4, int y4, int x, int y){
    double completeArea = area(x1,y1,x2,y2,x3,y3) + area(x1, y1, x4, y4, x3, y3);

    double a1 = area(x, y, x1, y1, x2, y2);
    double a2 = area(x, y, x2, y2, x3, y3);
    double a3 = area(x, y, x3, y3, x4, y4);
    double a4 = area(x, y, x4, y4, x1, y1);

    return (completeArea == (a1 + a2 + a3 + a4));
}
int main(){
    init();
    int d,n,m;
    cin >> n >> d >> m;
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        cout << ((isInside(0,d,d,0,n,n-d,n-d,n,x,y) == 1)?"YES\n":"NO\n");
    }
}
