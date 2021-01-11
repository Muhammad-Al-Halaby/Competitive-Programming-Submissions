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

int main(){
    init();

    string a, b;    cin >> a >> b;

    if(a == b)  return cout << "EQUAL", 0;
    if(a.size() > b.size()) return cout << "GREATER", 0;
    if(b.size() > a.size()) return cout << "LESS", 0;


    for(int i = 0;i < a.size();i++){
        if(a[i] > b[i]) return cout << "GREATER", 0;
        if(b[i] > a[i]) return cout << "LESS", 0;
    }

}