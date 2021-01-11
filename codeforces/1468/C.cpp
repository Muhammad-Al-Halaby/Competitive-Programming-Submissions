#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])
#define EPS 1e-9
#define PI acos(-1)
#define all(v) v.begin(),v.end()
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);


    int idx = 0;
    int q; cin>>q;
    set<pair<int, int>> poly, mono;
    while(q--)
    {
        int c; cin>>c;
        if(c == 1)
        {
            int m; cin>>m;
            poly.insert({-m, idx});
            mono.insert({idx, m});
            idx++;
        }
        if(c == 2)
        {
            pair<int, int> ans = *mono.begin();
            int idx = ans.first;
            int m = ans.second;

            cout<<idx + 1<<" ";
            mono.erase(ans);
            poly.erase({-m, idx});
        }
        if(c == 3)
        {
            pair<int, int> ans = *poly.begin();
            int idx = ans.second;
            int m = ans.first;

            cout<<idx + 1<<" ";
            poly.erase(ans);
            mono.erase({idx, -m});
        }
    }
}
