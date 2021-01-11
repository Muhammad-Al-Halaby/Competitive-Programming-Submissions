#include <bits/stdc++.h>

using namespace std;

#define pi               acos(-1)
#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(n)        (n).erase(unique(inc(n)), (n).end())
#define what_is(x)       cerr << #x << " is " << x << '\n';
#define to(i, a, n)      for(int i=a; i<n; i++)
#define fr(i, a, n)      for(int i=a; i>=n; i--)
#define read(arr, l, r)  for(int i=l; i<r; cin >> arr[i++])
#define prnt(arr, l, r)  for(int i=l; i<r; cout << arr[i++] << " \n"[i==r])

typedef long long ll;
typedef long double ld;

set<int> s;
map<int, int> x, y;
int n, b, d, point, mx, pr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> b >> d;
        s.insert(b), s.insert(d);
        x[b]++, y[d]++;
    }

    for(auto it:s){
        if(x[it]) pr += x[it];
        if(y[it]) pr -= y[it];

        if(pr > mx){
            mx = pr;
            point = it;
        }
    }
    cout << point << ' ' << mx;
}
