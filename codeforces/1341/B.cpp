#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, k;  cin >> n >> k;

        int a[n];
        vector<int> peaks;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }

        for(int i = 1;i < n - 1;i++){
            if(a[i] > a[i - 1] && a[i] > a[i + 1])
                peaks.push_back(i);
        }


        int ans = 0, mx = 0;
//
//        if(peaks.empty()){
//            cout << 0 << " " << 1;
//            return 0;
//        }


        for(int j = 0, i = 0;j < peaks.size() && i < peaks.size();i++){

            int r = (peaks[j] + 1);
            int l = (peaks[i] - 1);

            while(r - l + 1 <= k){
                int len = j - i + 1;
                if(len > mx){
                    mx = len;
                    ans = r;
                }
                j++;

                if(j == peaks.size())   break;

                r = (peaks[j] + 1);
            }
        }

        

ans = max((ans + 1) - k, 0);

        while(ans + k - 1 > n)ans--;

        cout << mx + 1 << " " << ans+1 << '\n';

    }


}