#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();
    string t, p;
    cin >> t >> p;
    map<int, int> mp;
    for(int i = 0;i < t.size();i++){
        int x;
        cin >> x;
        mp[x] = i;
    }

    auto check = [&](int lastidx){
        int j = 0;
        for(int i = 0;i < t.size();i++){
            if(mp[i+1] <= lastidx);
            else
                if(p[j] == t[i])j++;

            if(j == p.size())return 1;
        }
        return 0;
    };

    int l = 0, r = t.size();
    while(l <= r){
        int mid = (l+r) >> 1;
        if(check(mid))l = mid + 1;
        else r = mid - 1;
    }
    cout << l;
}