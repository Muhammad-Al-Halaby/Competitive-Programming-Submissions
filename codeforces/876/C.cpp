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

sumOfdigits(int n){
    int s = 0;
    while(n) s += n % 10, n /= 10;
    return s;
}

int main(){
    init();

    int n;
    cin >> n;

    vector<int> ans;

    for(int i = 1; i < 81;i++){
        int x = n - i;
        if(sumOfdigits(x) == i)
            ans.push_back(x);
    }
    
    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';
    for(int x : ans)
        cout << x << '\n';
}