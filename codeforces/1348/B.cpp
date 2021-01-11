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
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, k;  cin >> n >> k;

        set<int> s;
        for(int x, i = 0;i < n;i++){
            cin >> x;
            s.insert(x);
        }

        if(s.size() > k){
            cout << "-1\n";
            continue;
        }

        vector<int> v(s.begin(), s.end());
        while(v.size() < k) v.push_back(1);

        cout << n * k << '\n';
        for(int i = 0;i < n;i++)
            for(auto val : v)
                cout << val << " ";

        cout << '\n';
    }
}