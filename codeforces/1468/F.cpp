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
        int n; cin>>n;
        map<pair<ll, ll>, int> mp;
        for(int i = 0; i < n; i++)
        {
            ll x, y, u, v;
            cin>>x>>y>>u>>v;
            ll dx = u - x;
            ll dy = v - y;

            ll gcd = __gcd(abs(dx), abs(dy));
            dx /= gcd;
            dy /= gcd;


            mp[{dx, dy}]++;
        }

        ll ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            pair<ll, ll> p = it -> first;
            ll x = p.first;
            ll y = p.second;
            ll cnt= it -> second;
            ans += cnt * mp[{-x, -y}];
        }

        cout<<ans/2<<"\n";
    }
}
