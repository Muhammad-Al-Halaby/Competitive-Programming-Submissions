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

const int N = 109, M = 509, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int fr[N];

int main(){
    init();

    int n, m;   cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;   cin >> a >> b;
        fr[a]++;
        fr[b]++;
    }

    for(int i = 1;i <= n;i++)   cout << fr[i] << '\n';
}