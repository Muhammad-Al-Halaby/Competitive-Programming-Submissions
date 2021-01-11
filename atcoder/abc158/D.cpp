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

const int N = 3e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string s;   cin >> s;

    int q;  cin >> q;

    int state = 0;
    vector<char> add[2];
    for(int i = 0;i < q;i++){
        int t;  cin >> t;
        if(t == 1)  state ^= 1;
        else{
            int f;  char c; cin >> f >> c;
            f--;
            add[state ^ f].push_back(c);
        }
    }

    if(state)   reverse(s.begin(), s.end());
    reverse(add[state].begin(), add[state].end());
    for(auto c : add[state])    cout << c;
    cout << s;
    for(auto c : add[state ^ 1])    cout << c;

}