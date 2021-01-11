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
        ll n;  cin >> n;
        ll h = n / 2;
        ll sum = h * (h + 1);
        vector<int> ans;
        for(int i = 0, x = 2;i < h;i++, x += 2){
            ans.push_back(x);
        }
        for(int i = 0, x = 1;i < h;i++, x += 2){
            if(i + 1 == h && sum & 1){
                ans.push_back(sum);
                sum = 0;
            }
            else if(i + 1 < h && sum >= x){
                ans.push_back(x);
                sum -= x;
            }
        }

        if(sum){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(auto v : ans)
            cout << v << " ";
        cout << '\n';
    }
}