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

    int n;  cin >> n;

    int a[n];
    map<int, int> mp;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 1, f = a[0], s;
    for(int i = 0;i < n;i++){
        mp[a[i]]--;
        for(int j = 0;j < 31;j++){
            int cnt1 = mp.count(a[i] - (1 << j));
            int cnt2 = mp.count(a[i] + (1 << j));
            if(cnt1 && cnt2){
                return cout << 3 << '\n' << a[i] << " " << a[i] - (1 << j) << " " << a[i] + (1 << j), 0;
            }
            if(ans == 2)    continue;
            if(cnt1){
                ans = 2;
                f = a[i], s = a[i] - (1 << j);

            }
            if(cnt2){
                ans = 2;
                f = a[i], s = a[i] + (1 << j);
            }
        }
        mp[a[i]]++;
    }

    cout << ans << '\n' << f << " ";
    if(ans == 2)    cout << s;
}