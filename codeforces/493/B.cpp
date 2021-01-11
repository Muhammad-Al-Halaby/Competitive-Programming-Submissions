#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n;
    ll f=0,s=0,last;
    cin >> n;
    vector<int> o,e;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(x > 0)f+=x,o.push_back(x),last=1;
        else s -=x,e.push_back(abs(x)),last=0;
    }
    if(f > s)
        return cout << "first", 0;
    else if(s > f)
        return cout << "second", 0;
    else
        for(int i = 0;i<min(o.size(),e.size());i++)
            if(o[i] > e[i])return cout << "first", 0;
            else if(o[i] < e[i])return cout << "second", 0;

    if(o.size() > e.size())
        cout << "first";
    else if(e.size() > o.size())
        cout << "second";
    else
        if(last)
            cout << "first";
        else
            cout << "second";
}