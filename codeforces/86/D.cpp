#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N], root, freq[M], ql[N], qr[N], sorted[N], l, r;

ll ans, answers[N];

void update(int x, bool b){
    ans -= 1ll * a[x] * freq[a[x]] * freq[a[x]];
    freq[a[x]] += (b ? 1 : -1);
    ans += 1ll * a[x] * freq[a[x]] * freq[a[x]];
}

void movePointers(int L, int R){
    while(l > L)    update(--l, 1);
    while(r < R)    update(++r, 1);
    while(l < L)    update(l++, 0);
    while(r > R)    update(r--, 0);
}

int main(){
    init();

    cin >> n >> m;
    for(int i = 0;i < n;i++)    cin >> a[i];

    root = sqrt(n);

    for(int i = 0;i < m;i++)
        cin >> ql[i] >> qr[i], ql[i]--, qr[i]--, sorted[i] = i;

    sort(sorted, sorted + m, [](int x, int y){
            int bucket1 = ql[x] / root;
            int bucket2 = ql[y] / root;
            if(bucket1 != bucket2)  return bucket1 < bucket2;
            return qr[x] < qr[y];
         });

    r = -1;
    for(int i = 0;i < m;i++){
        movePointers(ql[sorted[i]], qr[sorted[i]]);
        answers[sorted[i]] = ans;
    }

    for(int i = 0;i < m;i++)    cout << answers[i] << '\n';
}