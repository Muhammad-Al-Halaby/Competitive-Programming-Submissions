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

const int N = 2e5 + 9, M = 200, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, a[N];

vector<int> idx[M + 1];

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= M;i++)   idx[i].clear();

        for(int i = 0;i < n;i++){
            cin >> a[i];
            idx[a[i]].push_back(i);
        }

        int ans = 1;
        for(int i = 1;i <= M;i++){
            int sz = idx[i].size();
            ans = max(ans, sz);
            for(int j = 0;j < sz / 2;j++){

                int x = idx[i][j];
                int z = idx[i][sz - (j + 1)];

                for(int k = 1;k <= M;k++){
                    if(k == i)  continue;
                    int st = upper_bound(idx[k].begin(), idx[k].end(), x) - idx[k].begin();
                    int en = lower_bound(idx[k].begin(), idx[k].end(), z) - idx[k].begin();
                    ans = max(ans, 2 * (j + 1) + (en - st));
                }
            }
        }

        cout << ans << '\n';
    }
}