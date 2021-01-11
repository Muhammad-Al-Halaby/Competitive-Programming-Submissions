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

const int N = 59, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


ll o1, o2, s1, s2;

int main(){
    init();

    int n;  cin >> n;

    // o1 - > even positive odd negative
    // o2 - > odd positive even negative
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        s1 += x;
        s2 += x;

        if(i & 1){
            if(s1 >= 0){
                o1 += 1 + s1;
                s1 = -1;
            }
            if(s2 <= 0){
                o2 += 1 + abs(s2);
                s2 = 1;
            }
        }
        else{
            if(s2 >= 0){
                o2 += 1 + s2;
                s2 = -1;
            }
            if(s1 <= 0){
                o1 += 1 + abs(s1);
                s1 = 1;
            }
        }
    }

    cout << min(o1, o2);
}