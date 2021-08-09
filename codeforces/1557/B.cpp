#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--){
        int n, k;   cin >> n >> k;

        int a[n];
        pair<int, int> b[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
            b[i] = {a[i], i};
        }

        sort(b, b + n);

        int sum = 0;
        vector<int> subs;
        for(int i = 0;i < n;i++){
            int l = b[i].second;
            int sz = 1;
//            cout << b[i].first << " ";
            while(i + 1 < n && l + 1 < n && b[i + 1].first == a[l + 1]){
                l++;
                i++;
                sz++;
//                cout << b[i].first << " ";
            }
//            cout << endl;
            subs.push_back(sz);
        }

        if(subs.size() > k){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
        
    }

}