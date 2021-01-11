#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<35> MASK;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<vector<ll>> vvi;

//set iterator can be increamnted and decreamnted
void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
struct node{
    int c,u,v;
};
const int MAX=1e4+5;
int A[MAX],F[MAX];
bool comp(node &a,node &b){
    return a.c<b.c;
}
int main() {
       fast();
        int n,m;cin>>n>>m;
        vector<node>ar;
    for (int i = 0; i <m ; ++i) {
        int u,v,c;cin>>u>>v>>c;
        ar.push_back({c,v,u});
        A[u]++;
        F[v]++;
    }
    for (int k = 1; k <=n ; ++k) {
    if(!A[k]||!F[k])return cout<<-1,0;
    }
    sort(all(ar),comp);
    for (int j = m-1; j >=0 ; --j) {
        A[ar[j].v]--;
        F[ar[j].u]--;
        if(!A[ar[j].v]||!F[ar[j].u])return cout<<ar[j].c,0;

    }

}
