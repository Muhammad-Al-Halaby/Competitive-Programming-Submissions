#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int picked[2000];

int main(){
    init();
    int n,r,heaters=0;
    cin >> n >> r;
    vector<pair<int,int> > v;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        if(x)v.push_back(make_pair(i-r+1,i+r-1));
    }

    if(v.empty())return cout << -1,0;
    int cover_point = 1;
    while(true){
        int mn = INT_MAX,ans=-1;
        for(int i = 0;i<v.size();i++){
            int f = v[i].F, s = v[i].S;
            if(!picked[i] && cover_point >= f && cover_point <= s){
                if(cover_point - f < mn){
                    mn = cover_point - f;
                    ans = i;
                }
            }
        }
        if(ans == -1)return cout << -1, 0;
        picked[ans] = 1;
        cover_point = v[ans].S + 1;
        heaters++;
        if(cover_point > n)break;

    }
    cout << heaters;
}