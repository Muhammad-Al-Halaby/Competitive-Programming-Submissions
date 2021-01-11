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
    ll n, m;
    cin >> n >> m;
    ll a[n], b[n];
    priority_queue<pair<ll,int> > pq;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < n;i++){
        cin >> b[i];
        pq.push(make_pair(-b[i] / a[i],i));
    }

    while(true){
        int idx = pq.top().S;
        ll old = -pq.top().F;

        if((b[idx] + m)/a[idx] == old)
            break;

        pq.pop();

        ll limit = -(pq.top().F) + 1;

        ll l = 1, r = m;

        while(l <= r){
            ll mid = (l+r) >> 1;

            if((b[idx] + mid)/a[idx] < limit)
                l = mid + 1;
            else
                r = mid - 1;
        }

        l = min(l, m);

        b[idx] += l;
        m -= l;

        pq.push(make_pair(-b[idx] / a[idx],idx));
    }

    cout << -pq.top().F;

}