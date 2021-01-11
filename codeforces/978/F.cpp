#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m;   cin >> n >> m;

    pii a[n];
    for(int i = 0;i < n;i++)    cin >> a[i].F, a[i].S = i;

    int ans[n] = {0};
    for(int i = 0;i < m;i++){
        int x, y;   cin >> x >> y;  x--, y--;
        if(a[x].F > a[y].F) ans[x]--;
        if(a[y].F > a[x].F) ans[y]--;
    }


    sort(a, a + n);

    for(int i = 0;i < n;i++){
        int j = a[i].S;
        int l = 0, r = i - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(a[mid].F == a[i].F)  r = mid - 1;
            else l = mid + 1;
        }

        ans[j] += l;
    }

    for(int i = 0;i < n;i++)    cout << ans[i] << " ";

}