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


    int t; cin>>t;
    while(t--)
    {
        int a[4];
        for(int i = 0; i < 4; i++)
            cin>>a[i];

        sort(a, a + 4);
        cout<<a[0] * a[2]<<"\n";
    }
}
