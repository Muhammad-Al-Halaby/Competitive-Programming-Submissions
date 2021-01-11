#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int sumOfdigits(int n){
    int s = 0;
    while(n) s += n % 10, n /= 10;
    return s;
}
int main(){
    init();
    int n;
    cin >> n;
    int rem[3] = {0};
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        rem[sumOfdigits(x)%3]++;
    }
    cout << rem[0] / 2 + min(rem[1],rem[2]);
}