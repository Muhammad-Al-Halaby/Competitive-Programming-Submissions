#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

const int MAX_SIZE = 1e6;
int t[2 * MAX_SIZE];
int n;

void build(){
    for(int i = n - 1; i > 0;i--)
        t[i] = max(t[i << 1],t[i << 1 | 1]);
}

int query(int l, int r){
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) res = max(res,t[l++]);
        if(r & 1) res = max(res, t[--r]);
    }
    return res;
}

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    
    int sum = 0;
    
    cin >> n;
    
    int w[n];
    
    for(int i = 0;i<n;i++){
        cin >> w[i] >> t[n+i];
        sum += w[i];
    }
    
    build();
    
    for(int i = 0;i<n;i++)
        cout << (sum - w[i]) * max(query(0,i),query(i+1,n)) << " ";
    
}