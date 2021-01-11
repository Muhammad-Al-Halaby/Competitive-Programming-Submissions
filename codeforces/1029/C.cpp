#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,l,r;
    cin >> n;
    pair<pair<int,int>,pair<int,int> > p[n];
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        p[i].first.first = y-x+1;
        p[i].first.second = i+1;
        p[i].second.first = x;
        p[i].second.second = y;

        if(i == 0)l=x,r=y;
        if(i > 0)
            l = max(l,x), r = min(r,y);
    }
    int ans1 = 0,ans2 = 0, len0 = max(0,r-l), len1, len2,rmvl=l,rmvr=r,pick=1;

    sort(p,p+n);

    l = -1,r = INT_MAX;

    for(int i = 0;i<n;i++){
        if(pick && p[i].second.first == rmvl){
            pick = 0;
            continue;
        }
        l = max(p[i].second.first,l);
        r = min(p[i].second.second,r);
    }
    len1 = max(0,r-l);

    l = -1,r = INT_MAX, pick = 1;

    for(int i = 0;i<n;i++){
        if(pick && p[i].second.second == rmvr){
            pick = 0;
            continue;
        }
        l = max(p[i].second.first,l);
        r = min(p[i].second.second,r);
    }
    len2 = max(0,r-l);

    if(len0 >= len1 && len0 >= len2)
        cout << len0;
    else if(len1 > len2)
        cout << len1;
    else
        cout << len2;
}