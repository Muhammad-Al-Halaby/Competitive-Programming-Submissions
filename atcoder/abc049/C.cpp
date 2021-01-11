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

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string a[] = {"dream", "dreamer", "erase", "eraser"};
    string  s;  cin >> s;
    int n = s.size();
    for(int i = n - 1;i >= 0;i--){
        string w = s.substr(i);
        for(int j = 0;j < 4;j++)    if(w == a[j]){
            s.erase(i);
        }
    }

    cout << (s.empty() ? "YES" : "NO");
}