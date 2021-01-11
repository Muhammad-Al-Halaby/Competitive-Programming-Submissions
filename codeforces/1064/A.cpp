#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int abc[3];
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc,abc+3);
    cout << max(0,1+abc[2] - (abc[0]+abc[1]));
}