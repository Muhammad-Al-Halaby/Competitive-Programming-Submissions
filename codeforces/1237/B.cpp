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

const int N = 1e5 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int out[N];

int main(){
    init();

    int n;  cin >> n;

    queue<int> q;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        q.push(x);
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        out[x] = 1;

        if(x == q.front()){
            q.pop();
            while(!q.empty() && out[q.front()])   q.pop();
            continue;
        }

        ans++;
    }

    cout << ans;
}
