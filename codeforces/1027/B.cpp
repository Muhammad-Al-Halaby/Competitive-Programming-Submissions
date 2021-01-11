#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 	3.14159265358979323846

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int m[] = {1,-1};

int main(){
    init();
    ll n,q,rowevens,rowodds;
    cin >> n >> q;
    rowodds = rowevens = n / 2;
    if(n % 2)rowodds++;

    for(int i = 0;i<q;i++){
        ll x,y,xx,yy;
        cin >> x >> y;
        ll odd1,odd2,even1,even2;
        xx = x;
        yy = y;
        x--;
        y = n;
        odd1 = even1 = x / 2;
        odd2 = even2 = y / 2;
        if(x%2)odd1++;
        if(y%2)odd2++;

        ll num_of_evens_in_previous_rows = odd1 * odd2 + even1 * even2;
        ll num_of_previous_evens_in_same_row = ceil(yy * 1.0 / 2);

        ll num_of_odds_in_previous_rows = odd1 * even2 + even1 * odd2;
        ll num_of_previous_odds_in_same_row = ceil(yy * 1.0 / 2);

        long long h = ceil((long double)n*n*1.0 / 2);
        if((xx+yy) % 2 == 0)
            cout << num_of_evens_in_previous_rows+num_of_previous_evens_in_same_row;
        else
            cout << h + (num_of_odds_in_previous_rows+num_of_previous_odds_in_same_row);
        cout << '\n';
    }
}
