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

ll MOD = 14458748209111; // (1e9 + 7);
ll BASE = 257;

inline ll shiftLeft(ll hashCode){
    hashCode *= BASE;
    while(hashCode >= MOD)
        hashCode -= MOD;
    return hashCode;
}

inline ll addAt(ll hashCode, int val){
    hashCode += val;
    while(hashCode >= MOD)
        hashCode -= MOD;
    return hashCode;
}

set<ll> ss;

int main(){
    init();
    string s;
    cin >> s;
    int alpha[26], arr[s.size()+1], k;
    arr[0] = 0;
    for(int i = 0;i < 26;i++){
        char c;
        cin >> c;
        alpha[i] = (c-'0') ^ 1;
    }

    for(int i = 0;i < s.size();i++)
        arr[i + 1] = alpha[s[i] - 'a'];

    partial_sum(arr,arr+s.size()+1,arr);

    cin >> k;

    for(int i = 0;i < s.size();i++){
        ll  pCode = 0;
        for(int j = i;j < s.size();j++){
            pCode = shiftLeft(pCode);
            pCode = addAt(pCode, s[j]);
            if(arr[j+1] - arr[i] <= k)ss.insert(pCode);
            else break;
        }
    }

    cout << ss.size();
}
