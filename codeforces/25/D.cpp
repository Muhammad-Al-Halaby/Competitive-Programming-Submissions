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
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
int n, m;
int dsu[1005];
int visited[1005];

int findroot(int i){
    if(i == dsu[i])
        return i;
    return dsu[i] = findroot(dsu[i]);
}

int main(){
    init();

    cin >> n;

    for(int i = 1;i <= n;i++)
        dsu[i] = i;

    vector<pii> oldroads;
    vector<int> newroads;
    for(int i = 0;i < n-1;i++){
        int a, b;
        cin >> a >> b;
        int aroot = findroot(a);
        int broot = findroot(b);
        if(aroot == broot)oldroads.push_back(MP(a,b));
        else{
            dsu[broot] = aroot;
        }
    }


    for(int i = 1;i <= n;i++){
        int root = findroot(i);
        if(!visited[root]){
            newroads.push_back(i);
            visited[root] = 1;
        }
    }

    cout << oldroads.size() << '\n';
    for(int i = 0;i < oldroads.size();i++){
        cout << oldroads[i].F << " " << oldroads[i].S << " " << newroads[i] << " " << newroads[i+1] << '\n';
    }
}