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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void solve(){

    int n;  cin >> n;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    sort(a, a + n);

    int cnt = 1;
    for(int i = 0;i < n;i++){
        if(a[i] <= cnt){
            cnt++;
            continue;
        }

        int j, temp = 0, ok = 0;
        for(j = i;j < n;j++){
            if(temp + cnt >= a[j]){
                temp++;
                ok = 1;
                break;
            }
            temp++;
        }

        if(!ok) break;

        i = j;
        cnt += temp;
    }

    cout << cnt << '\n';
}



int main(){
    init();

    int t;  cin >> t;
    while(t--)  solve();
}