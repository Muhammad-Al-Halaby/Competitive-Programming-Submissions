#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define EPS 1e-8

struct point{
    int x;
    int y;
};

point calcVector(point a, point b){
    point p;
    p.x = b.x - a.x;
    p.y = b.y - a.y;
    return p;
}

int crossproduct(point vec1, point vec2){
    return vec1.x * vec2.y - vec1.y * vec2 .x;
}
bool isCollinear(point a, point b, point c){
    if(fabs(crossproduct(calcVector(a,b),calcVector(a,c))) < EPS)
        return 1;
    return 0;
}


int flag[1005];

int main(){
    int n,x,y,lines = 0;
    cin >> n >> x >> y;
    point p0;
    p0.x = x;p0.y = y;
    point points[n];
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        points[i].x = a;
        points[i].y = b;
    }

    for(int i = 0;i<n;i++){
        if(!flag[i]){
            for(int j = i+1;j<n;j++){
                if(!flag[j] && isCollinear(p0,points[i],points[j]))
                {
                    flag[j] = 1;
                }
            }
            flag[i] = 1;
            lines++;
        }
    }
    cout << lines;
}