#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

set<int> fac;

void getFactors(int x){
    for(ll i = 2; i * i <= x;i++){
        if(x % i)continue;
        fac.insert(i);
        while (x % i == 0) x /= i;
    }
    if(x > 1)fac.insert(x);
}

int main(){
    init();

    int n;
    cin >> n;

    map<int,int> mp;

    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;

        if(i == 0){
            getFactors(a);
            getFactors(b);
            for(auto f : fac)mp[f]++;
            continue;
        }

        for(auto f : fac)
            if(a % f == 0 || b % f == 0)mp[f]++;
    }
    for(auto f : fac)
        if(mp[f] == n)
            return cout << f, 0;
    
    cout << -1;
}