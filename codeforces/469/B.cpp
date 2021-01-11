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
#define EPS 1e-6


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int prefix[(int)1e5+5];
int seen[(int)1e5+5];
int freq[(int)1e5+5];

int main(){
    init();
    int p,q,l,r,ans=0;
    cin >> p >> q >> l >> r;
    pair<int,int> ps[p];
    pair<int,int> qs[q];
    for(int i = 0;i<p;i++)
        cin >> ps[i].first >> ps[i].second;
    for(int i = 0;i<q;i++)
        cin >> qs[i].first >> qs[i].second;
    for(int i = l;i<=r;i++){
        for(int j = 0;j<q;j++){
            for(int k = 0;k<p;k++){
                int s = max(ps[k].first,qs[j].first+i);
                int e = min(ps[k].second,qs[j].second+i);
                if(s > e)continue;
                else{
                    ans++;
                    seen[i]++;
                    break;
                }
            }
            if(seen[i])break;
        }
    }
    cout << ans;
}