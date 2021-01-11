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

const int N = 2e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int a[N], b[N], buckets[N], root;

int main(){
    int n;  cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int i = 0;i < n;i++)    cin >> b[i];

    root = sqrt(n) + 300;

    for(int i = n - 1;i >= 0;i--){
        buckets[i] = a[i] - b[i];
        if(i % root == 0)   sort(buckets + i, buckets + min(n, i + root));
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        int x = b[i] - a[i];
        for(int j = 0;j < i;j++){
            if(j % root == 0 && j + root - 1 < i){
                int idx = upper_bound(buckets + j, buckets + min(n, j + root), x) - buckets;
                int lst = j / root * root + root;
                ans += lst - idx;
                j += root - 1;
            }
            else ans += (a[j] - b[j]) > x;
        }
    }

    cout << ans;
}