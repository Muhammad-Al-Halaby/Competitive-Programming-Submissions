#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 100 + 10, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    int n;  cin >> n;

    int cnt[N] = {0}, fr[N] = {0};


    vector<int> un;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        cnt[x]++;
        if(find(un.begin(), un.end(), x) == un.end())
            un.push_back(x);
    }

    n = un.size();
    for(int i = 0;i < n;i++){
        int x = un[i];
        fr[x * 2] += cnt[x] / 2;
        for(int j = i + 1;j < n;j++){
            int y = un[j];
            fr[x + y] += min(cnt[x], cnt[y]);
        }
    }

    cout << *max_element(fr, fr + N) << '\n';
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
   cin >> t;
    while(t--)
        go(tc++);
}